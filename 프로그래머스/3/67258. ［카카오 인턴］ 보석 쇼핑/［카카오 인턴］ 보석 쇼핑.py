from collections import defaultdict


def solution(gems):
    total_types = len(set(gems))
    gem_count = defaultdict(int)

    left = 0
    answer = [1, len(gems)]
    min_len = float('inf')

    for right in range(len(gems)):
        gem_count[gems[right]] += 1

        while len(gem_count) == total_types:
            current_len = right - left + 1

            if current_len < min_len:
                min_len = current_len
                answer = [left + 1, right + 1]

            gem_count[gems[left]] -= 1

            if gem_count[gems[left]] == 0:
                del gem_count[gems[left]]
            
            left += 1

    return answer