from math import floor, exp
from random import choice, randrange

def check_win(board):
    if board[0] == board[1] == board[2] and board[0] != 0.5:
        return True
    elif board[3] == board[4] == board[5] and board[3] != 0.5:
        return True
    elif board[6] == board[7] == board[8] and board[6] != 0.5:
        return True
    elif board[0] == board[3] == board[6] and board[0] != 0.5:
        return True
    elif board[1] == board[4] == board[7] and board[1] != 0.5:
        return True
    elif board[2] == board[5] == board[8] and board[2] != 0.5:
        return True
    elif board[0] == board[4] == board[8] and board[0] != 0.5:
        return True
    elif board[2] == board[4] == board[6] and board[2] != 0.5:
        return True
    else:
        return False

def get_win_draw_or_lose_value_for_O(board):
    if board[0] == board[1] == board[2] == board[3] == board[4] == board[5] == board[6] == board[7] == board[8] != 0.5:
        return 0;
    if board[0] == board[1] == board[2] == 0.0:
        return 10
    if board[3] == board[4] == board[5] == 0.0:
        return 10
    if board[6] == board[7] == board[8] == 0.0:
        return 10
    if board[0] == board[3] == board[6] == 0.0:
        return 10
    if board[1] == board[4] == board[7] == 0.0:
        return 10
    if board[2] == board[5] == board[8] == 0.0:
        return 10
    if board[0] == board[4] == board[8] == 0.0:
        return 10
    if board[2] == board[4] == board[6] == 0.0:
        return 10
    if (check_win(board)):
        return -10
    return 5

def get_next_possible_random_moves_move(board):
    next_moves = randrange(0,8)

    while (board[next_moves] != 0.5):
        next_moves = randrange(0,8)

    return next_moves

def generate_X_Boards(x):
    new_boards = []
    game_length = 0
    while len(new_boards) < x:
        board = [0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5]
        turn = 1.0
        fix = 0
        game_length = choice([1,3,5,7])

        for j in range(0, game_length):
            board[get_next_possible_random_moves_move(board)] = turn
            if get_win_draw_or_lose_value_for_O(board) != 5:
                break

            if turn == 1.0:
                turn = 0.0
            elif turn == 0.0:
                turn = 1.0
            fix = 1
        if board not in new_boards and fix == 1:
            new_boards.append(board)
    return new_boards

def get_next_turn(board):
    if board.count(0.5) % 2 == 0:
        return 1.0
    else:
        return 0.0

def get_best_next_move(board, next_move, iterations):
    if iterations > 8:
        return 0.0
    if board[next_move] != 0.5:
        return 0.0
    new_board = board.copy()

    new_board[next_move] = get_next_turn(board)
    if get_win_draw_or_lose_value_for_O(board) == 10.0:
        return 30.0 - iterations
    elif get_win_draw_or_lose_value_for_O(board) == -10.0:
        return 9.0 - iterations
    elif get_win_draw_or_lose_value_for_O(board) == 0.0:
        return 18.0-iterations
    else:
        return max([get_best_next_move(new_board, i, iterations + 1) for i in range(9)])

def max_for_list(list):
    max = list[0]
    for i in list:
        if i > max:
            max = i
    return max

def sum_for_list(list):
    sum = 0.0
    for i in list:
        sum += i
    return sum

def softmax(vector):
    max = max_for_list(vector)
    sum = 0

    for value in range(len(vector)):
        if vector[value] != 0.0:
            vector[value] = floor(exp(vector[value] - max) * 1000) / 1000
        sum += vector[value]
    for value in range(len(vector)):
        if vector[value] != 0.0:
            vector[value] /= sum

    return vector

def relu(vector):
    for value in range(len(vector)):
        if vector[value] < 0:
            vector[value] = 0
    return vector

def calculate_probabilities(boards):
    probabilities = []
    for board in boards:
        probabilit = []
        for i in range(9):
            if board[i] == 0.5:
                probabilit.append(get_best_next_move(board, i, 0))
            else:
                probabilit.append(0.0)

        probabilities.append(softmax(probabilit))

    return probabilities

def get_string_list(list):
    string = ""
    for i in list:
        string += " " + str(i)
    return string

def get_string_file(boards, probabilities):
    string = str(len(boards))
    for i in range(len(boards)):
        string += get_string_list(boards[i]) + get_string_list(probabilities[i])
    return string


def write_to_file(boards, probabilities):
    string = get_string_file(boards, probabilities)
    with open("database.txt", "w") as file:
        file.write(string)
        file.close()

#1035
boards = generate_X_Boards(1035)
print("Boards generated")

probabilities = calculate_probabilities(boards)
print("Probabilities calculated")

write_to_file(boards, probabilities)
print("File written")

print("Done")
#this is the worst#this is the worse code i could have written, but it works, and i am happy with it, so deal with it! code i could have written, but it works, and i am happy with it!:)
