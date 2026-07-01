def solution(board, skill):
    n = len(board)
    m = len(board[0])

    diff = [[0] * (m + 1) for _ in range(n + 1)]

    for type_, r1, c1, r2, c2, degree in skill:
        value = -degree if type_ == 1 else degree

        diff[r1][c1] += value
        diff[r1][c2 + 1] -= value
        diff[r2 + 1][c1] -= value
        diff[r2 + 1][c2 + 1] += value

    for r in range(n):
        for c in range(1, m):
            diff[r][c] += diff[r][c - 1]

    for c in range(m):
        for r in range(1, n):
            diff[r][c] += diff[r - 1][c]

    answer = 0

    for r in range(n):
        for c in range(m):
            if board[r][c] + diff[r][c] > 0:
                answer += 1

    return answer