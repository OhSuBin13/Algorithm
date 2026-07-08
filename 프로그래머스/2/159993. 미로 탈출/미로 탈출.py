from collections import deque


def solution(maps):
    n = len(maps)
    m = len(maps[0])

    start = lever = exit_ = None

    for i in range(n):
        for j in range(m):
            if maps[i][j] == 'S':
                start = (i, j)
            elif maps[i][j] == 'L':
                lever = (i, j)
            elif maps[i][j] == 'E':
                exit_ = (i, j)

    def bfs(src, dst):
        visited = [[False] * m for _ in range(n)]
        q = deque()

        sr, sc = src
        visited[sr][sc] = True
        q.append((sr, sc, 0))

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while q:
            r, c, dist = q.popleft()

            if (r, c) == dst:
                return dist
            
            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if nr < 0 or nr >= n or nc < 0 or nc >= m:
                    continue
                
                if visited[nr][nc] or maps[nr][nc] == 'X':
                    continue
                
                visited[nr][nc] = True
                q.append((nr, nc, dist + 1))

        return -1
    
    start_to_lever = bfs(start, lever)
    if start_to_lever == -1:
        return -1
    
    lever_to_exit = bfs(lever, exit_)
    if lever_to_exit == -1:
        return -1
    
    return start_to_lever + lever_to_exit