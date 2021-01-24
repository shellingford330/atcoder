def main(N, A):
  Max = 0
  for l in range(N):
    Min = 100000
    for r in range(l, N):
      Min = min(A[r], Min)
      Max = max(Min * (r - l + 1), Max)
  print(Max)
  return

N = int(input())
A = list(map(int, input().split()))

main(N, A)