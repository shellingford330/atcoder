def dfs(N, S, i):
  if i == N:
    return 1
  if S[i] == "OR":
    return 2 ** (N - i) + dfs(N, S, i+1)
  return dfs(N, S, i+1)

def main(N, S):
  S = S[::-1]
  print(dfs(N, S, 0))
  return

N = int(input())
S = [ input() for _ in range(N) ]
main(N, S)