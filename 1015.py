N = int(raw_input())
a = map(int, raw_input().split(' '))
a = [ {"original_index": i, "changed_index": -1, "value": a[i] } for i in xrange(len(a)) ]

sorted_a = sorted(a, key=lambda x: (x["value"], x["original_index"]))
r = [0] * N
for i,x in enumerate(sorted_a):
  r[x["original_index"]] = i
print ' '.join(str(i) for i in r)