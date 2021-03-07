def main(N, A):
  sum_A = [0]
  sum_double_A = [0]
  for i, a in enumerate(A):
    sum_A.append(sum_A[i] + a)
    sum_double_A.append(sum_double_A[i] + a ** 2)
  ans = 0
  for i, a in enumerate(A):
    ans += (a ** 2) * i - 2 * a * sum_A[i] + sum_double_A[i]
  print(ans)
  return

N = int(input())
A = list(map(int, input().split()))
main(N, A)