def solution(storey):
    answer = 0

    while storey > 0:
        digit = storey % 10
        next_digit = (storey // 10) % 10

        if digit < 5:
            answer += digit
            storey //= 10

        elif digit > 5:
            answer += 10 - digit
            storey = storey // 10 + 1

        else:
            answer += 5

            if next_digit >= 5:
                storey = storey // 10 + 1
            else:
                storey //= 10

    return answer