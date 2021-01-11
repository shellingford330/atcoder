def main(N, A, B):
  AAB = [ A[i]+A[i]+B[i] for i in range(N) ]
  diff = sum(A) - 0
  AAB.sort()
  ans = 0
  while diff >= 0:
    diff -= AAB.pop()
    ans += 1
  print(ans)

N = int(input())
A = []
B = []
for i in range(N):
  a, b = map(int, input().split())
  A.append(a)
  B.append(b)

main(N, A, B)