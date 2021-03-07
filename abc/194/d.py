def main(N):
  ans = 0.0
  for i in range(N-1):
    ans += N / (i+1)
  print(f"{ans:.10f}")
N = int(input())
main(N)