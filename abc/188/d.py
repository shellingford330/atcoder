def main(N, C, a, b, c):
  event = []
  for ta, tb, tc in zip(a, b, c):
    event.append((ta, tc))
    event.append((tb+1, -tc))
  event.sort()
  ans = 0
  fee = 0
  t = 0
  for x, y in event:
    if x != t:
      ans += min(C, fee) * (x - t)
      t = x
    fee += y
  print(ans)
  return

N, C = map(int, input().split())
a = []; b = []; c = []
for _ in range(N):
  ta, tb, tc = map(int, input().split())
  a.append(ta); b.append(tb); c.append(tc)
main(N, C, a, b, c)