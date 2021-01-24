def main(N, A):
  middle = pow(2, N-1)
  second_point = min(max(A[:middle]), max(A[middle:]))
  print(A.index(second_point) + 1)
  return

N = int(input())
A = list(map(int, input().split()))

main(N, A)