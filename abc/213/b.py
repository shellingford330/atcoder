def main(a):
  na = a.copy()
  na = sorted(na, reverse=True)
  print(a.index(na[1]) + 1)
  return



n = int(input())
a = list(map(int, input().split()))
main(a)