t = int(raw_input())
buttons = [300,60,10]

if t % 10 == 0:
  for time in buttons:
    counts = 0
    if t > time:
      counts += t/time
      t -= time * (t/time)
      # print(t)
    print(str(counts)),
else:
  print(-1)

