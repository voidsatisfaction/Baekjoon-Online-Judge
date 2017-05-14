N = int(raw_input())
ans = 0
for _ in xrange(N):
  a,b = map(int,raw_input().split(' '))
  ans += (b % a)

print ans