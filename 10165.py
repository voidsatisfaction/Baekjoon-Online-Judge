N = input()
M = input()
std_seg = {}
segs = []
ans = [ 0 for i in xrange(M+1) ]
lowest_a = N

for i in xrange(M):
  a,b = map(int,raw_input().split(' '))
  if a > b:
    if a < lowest_a:
      lowest_a = a
    a = a - N
  segs.append({ "from": a, "to": b, "index": i+1 })

sorted_segs = sorted(segs, key=lambda x: (x["from"], -x["to"]))

std_seg = sorted_segs[0]
ans[std_seg["index"]] = 1

for i in xrange(1,M):
  seg = sorted_segs[i]
  if seg["from"] >= lowest_a:
    break
  if std_seg["to"] < seg["to"]:
    ans[seg["index"]] = 1
    std_seg = seg

for i in xrange(M+1):
  if ans[i] == 1:
    print str(i),