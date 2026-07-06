from collections import deque

def solution(x, y, n):
    if x == y:
      return 0

    visited = [-1] * (y + 1)
    visited[x] = 0

    q = deque([x])

    while q:
       cur = q.popleft()

       for nxt in (cur + n, cur * 2, cur * 3):
          if nxt <= y and visited[nxt] == -1:
             visited[nxt] = visited[cur] + 1

             if nxt == y:
                return visited[nxt]
             
             q.append(nxt)

    return -1