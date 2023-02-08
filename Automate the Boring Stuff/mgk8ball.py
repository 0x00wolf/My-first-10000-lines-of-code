import random
import sys

messages = [
    'It is certain', 
    'It is decidedly so!',
    'Yes definitely',
    'Reply hazy try again',
    'Ask again later',
    'Concentrate and ask again',
    'My reply is no',
    'Outlook not so good',
    'Very doubtful'
]
while True:
    try:
        print('\nI am a magic 8 ball!\nAsk me any yes or no question:')
        question = input('')
        print(messages[random.randint(0, len(messages) - 1)])
    except KeyboardInterrupt:
        sys.exit()