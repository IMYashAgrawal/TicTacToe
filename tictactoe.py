def display(board):
    print()
    for row in board:
        print("  ".join(row))
    print()

def result(board):
    winner = '_'
    if board[0][0] != '_' and board[0][0] == board[1][1] == board[2][2]:
        winner = board[0][0]
    elif board[0][2] != '_' and board[0][2] == board[1][1] == board[2][0]:
        winner = board[0][2]
    else:
        for i in range(3):
            if board[i][0] != '_' and board[i][0] == board[i][1] == board[i][2]:
                winner = board[i][0]
                break
            elif board[0][i] != '_' and board[0][i] == board[1][i] == board[2][i]:
                winner = board[0][i]
                break
    if winner == 'x':
        print("Player 1 has won")
        return 1
    elif winner == 'o':
        print("Player 2 has won")
        return 1
    else:
        return 0

def player_input(board, turn):  # Renamed from 'input' to 'player_input'
    while True:
        if turn % 2 != 0:
            print("Player 1 chance: ", end="")
        else:
            print("Player 2 chance: ", end="")
        
        try:
            n, m = map(int, input().split())
            if 1 <= n <= 3 and 1 <= m <= 3:  
                if board[n - 1][m - 1] == '_': 
                    break
            print("Wrong Input, Retry")
            print()
        except ValueError:
            print("Invalid Input, Retry")
    
    if turn % 2 != 0:
        board[n - 1][m - 1] = 'x'
    else:
        board[n - 1][m - 1] = 'o'
    
    display(board)
    return result(board)

def game():
    board = [['_' for _ in range(3)] for _ in range(3)]
    print()
    print("For putting the x or o in your desired location you must enter the coordinates of the point. Select from the given below.")
    print("(1 1) (1 2) (1 3) (2 1) (2 2) (2 3) (3 1) (3 2) (3 3)")
    display(board)
    for i in range(1,9):
        if player_input(board, i):  
            return
    print("Match is draw")
    return

game()