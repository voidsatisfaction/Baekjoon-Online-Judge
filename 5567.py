N = int(raw_input())
M = int(raw_input())

graph = [[] for _ in xrange(N+1)]
for _ in xrange(M):
  a,b = map(int, raw_input().split(' '))
  graph[a].append(b)
  graph[b].append(a)

invited = set()
def dfs(a,depth):
  if depth == 0:
    return
  while graph[a]:
    friend = graph[a].pop()
    invited.add(friend)
    graph[friend].remove(a)
    dfs(friend,depth-1)

dfs(1,2)
print len(invited)