def main(N, M, A, B, K, C, D):
  pri = [0] * 101
  for a, b in zip(A, B):
    pri[a] += 1; pri[b] += 1
    
  is_on_desk = [False] * 101
  for c, d in zip(C, D):
    if is_on_desk[b] & is_on_desk[c]:
      continue
    if is_on_desk[b]:
      is_on_desk[c] = True
      continue
    if is_on_desk[c]:
      is_on_desk[b] = True
      continue
    if pri[c] >= pri[d]:
      is_on_desk[c] = True
    else:
      is_on_desk[d] = True
  ans = 0
  for a, b in zip(A, B):
    if is_on_desk[a] & is_on_desk[b]:
      ans += 1
  print(ans)
  return

N, M = map(int, input().split())
A, B = [0] * M, [0] * M
for i in range(M):
  A[i], B[i] = map(int, input().split())
K = int(input())
C, D = [0] * K, [0] * K
for i in range(K):
  C[i], D[i] = map(int, input().split())
main(N, M, A, B, K, C, D)