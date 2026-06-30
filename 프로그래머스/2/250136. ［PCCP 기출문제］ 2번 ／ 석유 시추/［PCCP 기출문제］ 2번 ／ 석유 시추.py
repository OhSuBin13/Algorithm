from collections import deque


def solution(land):
    n = len(land)
    m = len(land[0])

    oil_by_col = [0] * m
    visited = [[False] * m for _ in range(n)]

    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    for r in range(n):
        for c in range(m):
            if land[r][c] == 1 and not visited[r][c]:
                q = deque([(r, c)])
                visited[r][c] = True

                size = 0
                cols = set()

                while q:
                    x, y = q.popleft()
                    size += 1
                    cols.add(y)

                    for dx, dy in directions:
                        nx, ny = x + dx, y + dy

                        if 0 <= nx < n and 0 <= ny < m:
                            if land[nx][ny] == 1 and not visited[nx][ny]:
                                visited[nx][ny] = True
                                q.append((nx, ny))

                for col in cols:
                    oil_by_col[col] += size

    return max(oil_by_col)
