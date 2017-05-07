import math

def num_of_routes(p1,p2):
  p_x = p2["x"] - p1["x"]
  p_y = p2["y"] - p1["y"]
  num_array = [[1 for j in xrange(p_x+1)] for i in xrange(p_y+1)]
  for x in xrange(p_x+1):
    for y in xrange(p_y+1):
      if x > 0 and y > 0:
        num_array[y][x] = num_array[y-1][x] + num_array[y][x-1]
  
  return num_array[-1][-1]

N,M,K = map(int,raw_input().split(' '))
route_counts = 0

st = {"y": 0, "x": 0}
goal1 = {"y": (K-1)/M, "x": (K-1)%M}
goal2 = {"y": N-1, "x": M-1}

if K == 0:
  route_counts = num_of_routes(st,goal2)
else:
  route_counts = num_of_routes(st,goal1) * num_of_routes(goal1,goal2)

print route_counts