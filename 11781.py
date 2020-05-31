from math import inf
from heapq import heappush, heappop

N, M, S, E = [ int(c) for c in input().split(' ')]

node_time = [ inf for _ in range(N+1) ]
node_time[0] = 0
node_time[1] = 0

adj_list = [ [] for _ in range(N+1) ]

for _ in range(M):
    A, B, L, t1, t2 = [ int(c) for c in input().split(' ') ]

    adj_list[A].append((B, L, bool(t1) ))
    adj_list[B].append((A, L, bool(t2) ))

min_time_pq = []
heappush(min_time_pq, (0, 1))

while len(min_time_pq) > 0:
    time, node = heappop(min_time_pq)

    if time > node_time[node]:
        continue

    for edge in adj_list[node]:
        next_node, dist, slow = edge

        if slow is False:
            next_time = time + dist
        else:
            if time < S:
                if time + dist <= S:
                    next_time = time + dist
                elif 2*dist + 2*time - S > E:
                    next_time = time + (dist + (E - S)/2)
                else:
                    next_time = time + 2*dist + time - S
            elif time >= S and time < E:
                if time + 2*dist <= E:
                    next_time = time + 2*dist
                else:
                    next_time = time + dist + (E - time)/2
            else:
                next_time = time + dist
        
        if next_time < node_time[next_node]:
            node_time[next_node] = next_time
            heappush(min_time_pq, (next_time, next_node))

answer = max(node_time)
if answer == int(answer):
    print(int(answer))
else:
    print(f'{int(answer)}.5')