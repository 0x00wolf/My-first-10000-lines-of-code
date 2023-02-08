#! python3
# mclip.py - A multi-clipboard program

TEXT = {'agree': """Yes, I agree. That sounds fine to me!""",
        'busy': """Sorry, I'm busy at the moment. Could we touch base later?""",
        'upsell': """Don't bet on the horse, buy the track!"""
}

import sys
if len(sys.argv) < 2:
    print('Usage: python3 mclip.py [keyphrase] - copy phrase text')
    sys.exit()

keyphrase = sys.argv[1]

if keyphrase in TEXT:
    pyperclip.copy(TEXT[keyphrase])
    print('Text for ' + keyphrase + ' copied to clipboard.')
else:
    print('There is no text for ' + keyphrase)