import random

SUITS_TUPLE = ('Clubs', 'Spades', 'Hearts', 'Diamonds')
RANK_TUPLE = ('ACE', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'Jack', 'Queen', 'King')   

NCARDS = 8

def get_card(deck_list_in):
    """Pass in a card and returns a random card from the deck"""
    this_card = deck_list_in.pop()
    return this_card

def shuffle(deck_list_in):
    """Pass in a deck and return a shuffled copy of the deck"""
    deck_list_out = deck_list_in.copy()
    random.shuffle(deck_list_out)
    return deck_list_out

# Main code
print('Higher or Lower')
print('Guess whether the next card will be higher or lower.')
print('Right = +20 points.\nWrong = -15 points')
print('Start with 50 points\n')

starting_deck_list = []
for suit in SUITS_TUPLE:
    for value, rank in enumerate(RANK_TUPLE, start=1):
        card_to_add_to_dict = {'rank':rank, 'suit':suit, 'value':value}
        starting_deck_list.append(card_to_add_to_dict)

score = 50

while True:
    print()
    game_deck_list = shuffle(starting_deck_list)
    current_card_dict = get_card(game_deck_list)
    current_card_rank = current_card_dict['rank']
    current_card_value = current_card_dict['value']
    current_card_suit = current_card_dict['suit']

    print(f"Starting card is: {current_card_rank} of {current_card_suit}.\n")

    for card_number in range(0, NCARDS):
        answer = input(f"Will the next card be higher or lower than the "
            + f"{current_card_rank} of {current_card_suit}?\nEnter 'h' for higher, or 'l' for lower.")
        answer = answer.casefold()

        next_card_dict = get_card(game_deck_list)
        next_card_rank = next_card_dict['rank']
        next_card_value = next_card_dict['value']
        next_card_suit = next_card_dict['suit']
        print(f"Next card is the {next_card_rank} of {next_card_suit}.")

        if answer == 'h':
            if next_card_value > current_card_value:
                print("You're right, it was higher!")
                score = score + 20
            else:
                print('Can you take me higher?\n...\n\n...\nNope, it was lower!')
                score = score - 15

        elif answer == 'l':
            if next_card_value < current_card_value:
                print("You're right, it was lower!")
                score = score + 20
            else:
                print('It was higher, you were wrong!')
                score = score - 15

        else:
            print('Tie. No change in score!')
        print(f"Current score: {score}")
    print(f"\nYour final score is: {score}.\nWant to play again?")  
    go_again = input("'y' or 'n'?")
    if go_again == 'n':
        break
print("Bye for now, pal.")

        
