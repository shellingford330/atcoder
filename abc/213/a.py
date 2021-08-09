def main(a, b):
  for c in range(0, 256):
    if a ^ c == b:
      print(c)
      return

a, b = list(map(int, input().split()))
main(a, b)