N, M = map(int, input().split())
INF = 1000000000
f = [ [[INF for _ in range(N+1)] for _ in range(N+1) ] for _ in range(N+1) ]

for _ in range(M):
  a, b, c = map(int, input().split())
  f[a][b][0] = c

ans = 0
for k in range(1,N+1):
  for j in range(1,N+1):
    for i in range(1, N+1):
      if i == j:
        continue
      f[i][j][k] = min(f[i][j][k-1], f[i][k][k-1] + f[k][j][k-1])
      if f[i][j][k] != INF:
        ans += f[i][j][k]
print(ans)
