MAX = 101
n = int(raw_input())

num_array = [[-1 for i in xrange(MAX)] for j in xrange(MAX)]
area_array = [0 for i in xrange(n)]
for i in xrange(n):
  a,b,c,d = map(lambda n: int(n), raw_input().split(' '))
  for col in xrange(a,a+c):
    for row in xrange(b,b+d):
      num_array[row][col] = i
  
for i in xrange(MAX):
  for j in xrange(MAX):
    if num_array[i][j] != -1:
      area_array[num_array[i][j]] += 1

for i in xrange(n):
  print area_array[i]