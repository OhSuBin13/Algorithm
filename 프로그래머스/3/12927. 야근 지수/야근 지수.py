import heapq

def solution(n, works):
    if sum(works) <= n:
        return 0
    
    heap = [-work for work in works]
    heapq.heapify(heap)
    
    for _ in range(n):
        max_work = -heapq.heappop(heap)
        max_work -= 1
        heapq.heappush(heap, -max_work)

    return sum(work ** 2 for work in heap)