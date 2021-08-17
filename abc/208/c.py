N, K = map(int, input().split())
a = list(map(int, input().split()))

count = {}
na = sorted(a)
for ai in a:
  count[ai] = K // N
for i in range(K % N):
  count[na[i]] += 1
for ai in a:
  print(count[ai])
