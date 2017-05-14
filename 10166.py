from fractions import gcd

d1,d2 = map(int,raw_input().split(' '))
temp = set()
counts = 1

for d in xrange(d1,d2+1):
  for i in xrange(1,d):
    if (str(i) + '/' + str(d)) not in temp:
      gcd_i_d = gcd(i,d)
      dd = d / gcd_i_d
      ii = i / gcd_i_d
      j = 1
      while dd*j <= d2:
        temp.add(str(ii*j) + '/' + str(dd*j))
        j += 1
      counts += 1

print counts