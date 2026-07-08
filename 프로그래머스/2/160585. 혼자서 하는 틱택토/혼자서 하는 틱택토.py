def solution(board):
    o_count = sum(row.count('O') for row in board)
    x_count = sum(row.count('X') for row in board)

    if not (o_count == x_count or o_count == x_count + 1):
        return 0

    def win(mark):
        lines = []

        for i in range(3):
            lines.append([board[i][0], board[i][1], board[i][2]])  # Rows

        for j in range(3):
            lines.append([board[0][j], board[1][j], board[2][j]])  # Columns

        lines.append([board[0][0], board[1][1], board[2][2]])  # Diagonal
        lines.append([board[0][2], board[1][1], board[2][0]])  # Anti-diagonal

        return any(all(cell == mark for cell in line) for line in lines)
    
    o_win = win('O')
    x_win = win('X')

    if o_win and x_win:
        return 0
    
    if o_win and o_count != x_count + 1:
        return 0
    
    if x_win and x_count != o_count:
        return 0
    
    return 1