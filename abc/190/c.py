import itertools

def main(N, M, A, B, K, C, D):
  choice = zip(C, D)
  ans = 0
  for balls in itertools.product(*choice):
    balls = set(balls)
    cnt = sum(a in balls and b in balls for a, b in zip(A, B))
    ans = max(ans, cnt)
  print(ans)

N, M = map(int, input().split())
A, B = [0] * M, [0] * M
for i in range(M):
  A[i], B[i] = map(int, input().split())
K = int(input())
C, D = [0] * K, [0] * K
for i in range(K):
  C[i], D[i] = map(int, input().split())
main(N, M, A, B, K, C, D)