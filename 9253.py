from typing import List

A = input()
B = input()
U = input()


def KMP(string: str, target: str) -> List[int]:
    def create_failure_table(target: str) -> List[int]:
        failure_table = [0 for _ in range(len(target))]

        j=0
        for i in range(1, len(target)):
            while j>0 and target[i] != target[j]:
                j = failure_table[j-1]

            if target[i] == target[j]:
                j += 1
                failure_table[i] = j

        return failure_table
    
    matched_target_index_list = []

    target_failure_table = create_failure_table(target)

    j=0
    for i in range(0, len(string)):
        while j>0 and string[i] != target[j]:
            # j번째가 틀렸으므로, j를 fail(j)값으로 되돌림
            # 그런데, fail(j) = failure_table[j-1]
            j = target_failure_table[j-1]

        if string[i] == target[j]:
            if j == len(target)-1:
                matched_target_index_list.append(i-len(target)+1)
                # j+1번째에서 틀렸다고 가정하고 다시 j를 되돌림(j번째 까지는 맞았으므로)
                j = target_failure_table[j]
            else:
                j += 1

    return matched_target_index_list

if len(U) > len(A) or len(U) > len(B):
    print('NO')
elif len(KMP(A, U)) > 0 and len(KMP(B, U)) > 0:
    print('YES')
else:
    print('NO')