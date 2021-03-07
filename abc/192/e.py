import heapq

N, M, X, Y = map(int, input().split())
g = [[] for _ in range(N+1)]
for i in range(M):
  A, B, T, K = map(int, input().split())
  g[A].append((B, T, K))
  g[B].append((A, T, K))

INF = 10 ** 18
dist = [INF for _ in range(N+1)]
dist[X] = 0
q = [(0, X)]

while len(q) > 0:
  d, v = heapq.heappop(q)
  if d > dist[v]:
    continue
  for w, t, k in g[v]:
    nd = (d + k - 1) // k * k + t
    if nd < dist[w]:
      dist[w] = nd
      heapq.heappush(q, (nd, w))

if dist[Y] < INF:
  print(dist[Y])
else:
  print(-1)