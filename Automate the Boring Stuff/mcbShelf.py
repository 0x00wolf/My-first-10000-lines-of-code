#! python3
# mcb.pyw - Saves and loads pieces of text to the clipboard
# Usage: python3 mcb.pyw save <keyword> - Saves clipboard to keyword
#        python3 mcb.pyw <keyword> - loads keyword to clipboard
#        python3 mcb.pyw list - loads all the keywords to clipboard 

import shelve, pyperclip, sys

mcbShelf = shelve.open('mcb')

# TODO: save content to clipboard
if len(sys.argv) == 3 and sys.argv[1].lower() == 'save':
    mcbShelf[sys.argv[2]] == pyperclip.paste()
elif len(sys.argv) == 2:
# TODO: list keywords and load content
    if sys.argv[1].lower() == 'list':
        pyperclip.copy(str(list(mcbShelf.keys())))
    elif sys.argv[1] in mcbShelf:
        pyperclip.copy(mcbShelf[sys.argv[1]])
mcbShelf.close()