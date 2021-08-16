N = int(input())
S = list(map(int, input().split()))
T = list(map(int, input().split()))

now = T.index(min(T))

ans = [0 for _ in range(N)]
ans[now] = T[now]
for i in range(N-1):
  pre = now
  now = pre + 1
  if now == N:
    now -= N
  ans[now] = min(ans[pre] + S[pre], T[now])
for i in range(N):
  print(ans[i])