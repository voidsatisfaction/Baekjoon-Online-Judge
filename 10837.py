K = int(raw_input())
C = int(raw_input())
for _ in xrange(C):
  M,N = map(int,raw_input().split(' '))
  if M > N:
    if K - M + 1 >= M - N - 1:
      print 1
    else:
      print 0
  elif N > M:
    if K - N + 1 > N - M - 1:
      print 1
    else:
      print 0
  else:
    print 1
