from collections import deque

M, N = [int(i) for i in input().split(' ')]

original_map = [0 for _ in range(M)]
visited = {}

for row in range(M):
    col_list = [int(i) for i in input().split(' ')]
    original_map[row] = col_list

# east: 0, west: 1, ..., north: 3
start_state = tuple([int(i)-1 for i in input().split(' ')])
end_state = tuple([int(i)-1 for i in input().split(' ')])

def bfs(original_map, start_state, end_state) -> int:
    q = deque()

    q.append(start_state)
    visited[start_state] = True

    minimum_move_num = 0

    while True:
        q_length = len(q)

        for _ in range(q_length):
            state = q.popleft()
            y, x, d = state

            if state == end_state:
                return minimum_move_num

            if d == 0 or d == 1:
                next_state_list = [(y, x, 2), (y, x, 3)]
            elif d == 2 or d == 3:
                next_state_list = [(y, x, 0), (y, x, 1)]

            for next_state in next_state_list:
                if not visited.get(next_state):
                    visited[next_state] = True
                    q.append(next_state)
            
            for i in range(1, 4):
                if d == 0:
                    next_state = (y, x+i, d)
                elif d == 1:
                    next_state = (y, x-i, d)
                elif d == 2:
                    next_state = (y+i, x, d)
                else:
                    next_state = (y-i, x, d)

                next_y, next_x, next_d = next_state

                if next_y >= 0 and next_y < M and next_x >= 0 and next_x < N and original_map[next_y][next_x] == 1:
                    break

                if next_y < 0 or next_y >= M or next_x < 0 or next_x >= N or original_map[next_y][next_x] == 1 or visited.get(next_state):
                    continue

                visited[next_state] = True
                q.append(next_state)

        minimum_move_num += 1

print(bfs(original_map, start_state, end_state))