the_board = {
    'top-L': ' ', 'top-M': ' ', 'top-R': ' ',
    'mid-L': ' ', 'mid-M': ' ', 'mid-R': ' ',
    'low-L': ' ', 'low-M': ' ', 'low-R': ' '
}

def print_board(board):
    print(board['top-L'] + '|' + board['top-M'] + '|' + board['top-R'])
    print('-+-+-')
    print(board['mid-L'] + '|' + board['mid-M'] + '|' + board['mid-R'])
    print('-+-+-')
    print(board['low-L'] + '|' + board['low-M'] + '|' + board['low-R'])

turn = 'X'
for i in range(9):
    print_board(the_board)
    print('Turn for ' + turn + '. Move on which space')
    move = input()
    the_board[move] = turn
    if turn == 'X':
        turn = '0'
    else:
        turn = 'X'
