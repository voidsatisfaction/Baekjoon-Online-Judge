def seg_area(seg):
  return (seg["r"] - seg["l"])**2

MAX = 32768
n = int(raw_input())
temp = [0 for _ in xrange(MAX)]
segs = []

for _ in xrange(n):
  l,r = map(int, raw_input().split(' '))
  if r > temp[l]:
    temp[l] = r

for l in xrange(MAX):
  if (temp[l] == 0):
    continue
  segs.append({ "l": l, "r": temp[l] })

segs = sorted(segs, key=lambda x: x["l"])

last_seg = {}
ans = 0

for i, current_seg in enumerate(segs):
  if i == 0:
    ans += seg_area(current_seg)
    last_seg = current_seg
  else:
    if last_seg["r"] >= current_seg["r"]: continue
    
    ans += seg_area(current_seg)
    if i != 0 and last_seg["r"] > current_seg["l"]:
      ans -= seg_area({ "r": last_seg["r"], "l": current_seg["l"] })
    last_seg = current_seg

print ans