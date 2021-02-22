import math

def main(N):
  N *= 2
  ans = 0
  for i in range(int(math.sqrt(N))):
    if N % (i + 1) != 0:
      continue
    if N / (i + 1) % 2 + (i + 1) % 2 == 1:
      ans += 2
  print(ans)

N = int(input())
main(N)