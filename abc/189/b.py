def main(N, X, V, P):
  sum = 0
  for i, (v, p) in enumerate(zip(V, P)):
    sum += v * p
    if sum > X * 100:
      print(i+1)
      return
  print(-1)
  return

N, X = map(int, input().split())
V, P = [], []
for _ in range(N):
  v, p = map(int, input().split())
  V.append(v); P.append(p)

main(N, X, V, P)