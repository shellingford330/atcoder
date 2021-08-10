# おまじない
import sys
sys.setrecursionlimit(300000)

def dfs(parent, now):
  print(now, end=" ")
  for child in g[now]:
    if child == parent:
      continue
    dfs(now, child)
    print(now, end=" ")

n = int(input())
g = [ [] for _ in range(n+1)]
for _ in range(n-1):
  a, b = map(int, input().split())
  g[a].append(b)
  g[b].append(a)
for i in range(1,n+1):
  g[i].sort()
dfs(0, 1)
print()
