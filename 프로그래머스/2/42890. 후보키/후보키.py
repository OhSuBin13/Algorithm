def solution(relation):
    row_count = len(relation)
    column_count = len(relation[0])

    candidate_keys = []

    for mask in range(1, 1 << column_count):

        if any(
            (candidate_key & mask) == candidate_key
            for candidate_key in candidate_keys
        ):
            continue

        selected_rows = set()

        for row in relation:
            key = tuple(
                row[column]
                for column in range(column_count)
                if mask & (1 << column)
            )
            selected_rows.add(key)

        if len(selected_rows) == row_count:
            candidate_keys.append(mask)

    return len(candidate_keys)