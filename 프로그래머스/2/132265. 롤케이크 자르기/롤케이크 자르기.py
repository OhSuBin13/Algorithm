from collections import Counter

def solution(topping):
    answer = 0
    
    left = set()
    right = Counter(topping)

    left_count = 0
    right_count = len(right)

    for i in range(len(topping) - 1):
        t = topping[i]

        if t not in left:
            left.add(t)
            left_count += 1
        right[t] -= 1
        if right[t] == 0:
            right_count -= 1

        if left_count == right_count:
            answer += 1

    return answer