def solution(n, k, cmd):
    up = [i - 1 for i in range(n)]
    down = [i + 1 for i in range(n)]

    deleted = []

    current = k

    for command in cmd:
        if command[0] == "U":
            _, count = command.split()
            count = int(count)

            for _ in range(count):
                current = up[current]

        elif command[0] == "D":
            _, count = command.split()
            count = int(count)

            for _ in range(count):
                current = down[current]

        elif command[0] == "C":
            deleted.append((up[current], current, down[current]))

            upper = up[current]
            lower = down[current]

            if upper != -1:
                down[upper] = lower

            if lower != n:
                up[lower] = upper

            if lower != n:
                current = lower
            else:
                current = upper

        else:
            upper, restored, lower = deleted.pop()

            if upper != -1:
                down[upper] = restored
            
            if lower != n:
                up[lower] = restored

    answer = ["O"] * n

    for _, deleted_row, _ in deleted:
        answer[deleted_row] = "X"

    return "".join(answer)