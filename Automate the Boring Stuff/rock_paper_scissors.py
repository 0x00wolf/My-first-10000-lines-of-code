from multiprocessing import RLock
from random import randint
import sys
from time import sleep
wins = 0
losses = 0
ties = 0
while True:
    print("\nRock Paper Scissors")
    print("%s Wins %s Losses %s Ties" % (wins, losses, ties))
    computer_picks = randint(1, 3)
    if computer_picks == 1:
        computer_chooses = 'rock'
    elif computer_picks == 2:
        computer_chooses = 'paper'
    elif computer_picks == 3:
        computer_chooses = 'scissors'
    player_picks = input("Enter your move (r)ock, (p)aper, or (s)cissors or (q)uit: ")
    if player_picks == 'q':
        sys.exit()
    if player_picks == 'r':
        players_choice = 'rock'
    elif player_picks == 'p':
        players_choice = 'paper'
    else:
        players_choice = 'scissors'
    print('1 - rock')
    sleep(1)
    print('2 - paper')
    sleep(1)
    print('3 - scissors')
    sleep(1)
    print('Go!\n')
    sleep(1)
    print(f'Computer choose: {computer_chooses}, and you choose: {players_choice}.')
    if players_choice == 'rock' and computer_chooses == 'paper':
        print('Computer wins!')
        losses = losses + 1
    elif players_choice == 'rock' and computer_chooses == 'scissors':
        print('Player wins!')
        wins = wins + 1
    elif players_choice == 'rock' and computer_chooses == 'rock':
        print('Tie!')
        ties = ties + 1
    elif players_choice == 'paper' and computer_chooses == 'rock':
        print("Player wins!")
        wins = wins + 1
    elif players_choice == 'paper' and computer_chooses == 'paper':
        print('Tie!')
        ties = ties + 1
    elif players_choice == 'paper' and computer_chooses == 'scissors':
        print('Computer wins!')
        losses = losses + 1
    elif players_choice == 'scissors' and computer_chooses == 'rock':
        print('Computer wins!')
        losses = losses + 1
    elif players_choice == 'scissors' and computer_chooses == 'paper':
        print('Player wins!')
        wins = wins + 1
    elif players_choice == 'scissors' and computer_chooses == 'scissors':
        print('Tie!')
        ties = ties + 1
