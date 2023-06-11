# from pynput import keyboard
# from pynput.keyboard import Key, Listener
# import datetime

# Unfinished keylogger copies pynput docs:

# KEYSTROKE_LOG_FILE = './logs/keystroke.log'
# now = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

# class MyException(Exception): pass

# def on_press(key):
#     if key == keyboard.Key.esc:
#         raise MyException(key)

# # Collect events until released
# with keyboard.Listener(
#     on_press=on_press) as listener:
#     try:
#         listener.join()
#     except MyException as e:
#         print(' {0} was pressed' .format(e.args[0]))


###From pynput docs:###

# def on_press(key):
#     try:
#         print('alphanumeric key {0} pressed'.format(
#             key.char))
#     except AttributeError:
#         print('special key {0} pressed'.format(key))

# def on_release(key):
#     print('{0} released'.format(key))
#     if key == keyboard.Key.esc:
#         # Stop listener
#         return False
        
# # Collect events until released
# with keyboard.Listener(
#         on_press=on_press,
#         on_release=on_release) as listener:
#     listener.join()

# # in a non-blocking fashion
# listener = keyboard.Listener
#     on_press=on_press,
#     on_release=on_release)
# listener.start()


# Logging keystrokes
# with open(KEYSTROKE_LOG_FILE, 'a') as f:
#     line_to_write = f"{now}: Key Press - {key}"
#     f.write(f"{line_to_write}\n")
