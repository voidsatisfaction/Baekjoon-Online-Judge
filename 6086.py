import sys
from collections import deque
input = sys.stdin.readline

N = int(input())

def change(i):
    if i <= 'Z':
        return ord(i)-ord('A')
    return ord(i)-ord('a')+26

MAX_VERTEX = 52


capacity = [ [ 0 for _ in range(MAX_VERTEX) ] for _ in range(MAX_VERTEX) ]
flow = [ [ 0 for _ in range(MAX_VERTEX) ] for _ in range(MAX_VERTEX) ]
adj_list = [ [] for _ in range(MAX_VERTEX) ]

for _ in range(N):
    a, b, F = input().split()
    a, b = change(a), change(b)
    F = int(F)
    capacity[a][b] += F
    capacity[b][a] += F
    adj_list[a].append(b)
    adj_list[b].append(a)

total_flow = 0
source, sink = change('A'), change('Z')
while True:
    # find an augment path
    parent = [ -1 for _ in range(MAX_VERTEX) ]
    q = deque()
    q.append(source)

    while q and parent[sink] == -1:
        v = q.popleft()

        for next_v in adj_list[v]:
            if parent[next_v] == -1 and (capacity[v][next_v] - flow[v][next_v]) > 0:
                q.append(next_v)
                parent[next_v] = v

    # if there is no augment path, exit
    if parent[sink] == -1:
        break

    # find maximum amount which can flow for the augment path
    augment_path_max_amount = sys.maxsize
    v = sink
    while v != source:
        augment_path_max_amount = min(
            augment_path_max_amount,
            capacity[parent[v]][v] - flow[parent[v]][v]
        )
        v = parent[v]

    v = sink
    while v != source:
        flow[parent[v]][v] += augment_path_max_amount
        flow[v][parent[v]] -= augment_path_max_amount
        v = parent[v]

    total_flow += augment_path_max_amount

print(total_flow)

