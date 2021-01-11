import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

def main(S):
  set1 = { s[1:] for s in S if s[0] == '!' }
  set2 = { s for s in S if s[0] != '!' }
  set3 = set1 & set2
  if set3:
    print(set3.pop())
  else:
    print("satisfiable")
  

N = int(readline())
S = read().decode().split()
main(S)