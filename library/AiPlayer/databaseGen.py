def is_winner(board, player):
    win_conditions = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Rows
        [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Columns
        [0, 4, 8], [2, 4, 6]              # Diagonals
    ]
    return any(all(board[i] == player for i in combo) for combo in win_conditions)

def is_full(board):
    return all(cell != ' ' for cell in board)

def get_available_moves(board):
    return [i for i, cell in enumerate(board) if cell == ' ']

def minimax(board, depth, is_maximizing, ai_player, human_player):
    if is_winner(board, ai_player):
        return 10 - depth
    elif is_winner(board, human_player):
        return depth - 10
    elif is_full(board):
        return 0

    if is_maximizing:
        best_score = -float('inf')
        for move in get_available_moves(board):
            board[move] = ai_player
            score = minimax(board, depth + 1, False, ai_player, human_player)
            board[move] = ' '
            best_score = max(score, best_score)
        return best_score
    else:
        best_score = float('inf')
        for move in get_available_moves(board):
            board[move] = human_player
            score = minimax(board, depth + 1, True, ai_player, human_player)
            board[move] = ' '
            best_score = min(score, best_score)
        return best_score

def find_best_move(board, current_player, opponent):
    moves = get_available_moves(board)
    if not moves:
        return 0  # Terminal state: no moves, so store 0

    best_score = -float('inf') if current_player == 'X' else float('inf')
    best_move = 0  # Default to 0 if no better move found

    for move in moves:
        board[move] = current_player

        if current_player == 'X':
            score = minimax(board, 0, False, current_player, opponent)
            if score > best_score:
                best_score = score
                best_move = move
        else:
            score = minimax(board, 0, True, opponent, current_player)
            if score < best_score:
                best_score = score
                best_move = move

        board[move] = ' '

    return best_move

def board_to_binary_masks(board):
    X_mask = [1 if cell == 'X' else 0 for cell in board]
    O_mask = [1 if cell == 'O' else 0 for cell in board]
    empty_mask = [1 if cell == ' ' else 0 for cell in board]
    return X_mask, O_mask, empty_mask

def generate_and_save_states(board, current_player, states_with_moves, file_handle, visited):
    board_tuple = tuple(board)
    if board_tuple in visited:
        return
    visited.add(board_tuple)

    terminal = is_winner(board, 'X') or is_winner(board, 'O') or is_full(board)

    best_move = find_best_move(board, current_player, 'O' if current_player == 'X' else 'X') if not terminal else 0
    states_with_moves[board_tuple] = best_move

    X_mask, O_mask, empty_mask = board_to_binary_masks(board)
    line = [best_move] + X_mask + O_mask + empty_mask
    file_handle.write(" ".join(map(str, line)) + "\n")

    if terminal:
        return

    opponent = 'O' if current_player == 'X' else 'X'
    for move in get_available_moves(board):
        board[move] = current_player
        generate_and_save_states(board, opponent, states_with_moves, file_handle, visited)
        board[move] = ' '

# Usage:
initial_board = [' '] * 9
states_with_best_moves = dict()
visited = set()

with open("states.txt", "w") as f:
    generate_and_save_states(initial_board, 'X', states_with_best_moves, f, visited)

print(f"Saved {len(states_with_best_moves)} unique legal Tic Tac Toe states with best moves to 'states.txt'.")

