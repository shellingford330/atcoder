h, w, n = map(int, input().split())
a = []
b = []
for i in range(n):
  ta, tb = map(int, input().split())
  a.append(ta)
  b.append(tb)

y = {}; x = {}
na = a.copy()
nb = b.copy()
na = sorted(list(set(na)))
nb = sorted(list(set(nb)))
for i, ta in enumerate(na):
  x[ta] = i + 1
for i, tb in enumerate(nb):
  y[tb] = i + 1

for i in range(n):
  print(x[a[i]], y[b[i]])
