def main(H, W, S):
  ans = 0
  for h in range(H-1):
    for w in range(W-1):
      cnt = 0
      for hi in range(2):
        for wi in range(2):
          if S[h + hi][w + wi] == '#':
            cnt += 1
      if cnt == 1 or cnt == 3:
        ans += 1
  print(ans)
      
H, W = map(int, input().split())
S = [input() for _ in range(H)]
main(H, W, S)