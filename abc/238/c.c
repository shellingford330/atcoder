#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 100001
#define MOD 998244353
#define INF 1000000009
#define INV 499122177

int main(void) {
  long long N;
  scanf("%lld", &N);

  long long ans = 0;
  long long div = 1;
  long long add, max;
  for (N / (div * 10)) {
    max = 9 * div;
    add = (((1 + max) * max) % MOD) * INV % MOD;
    ans = (ans + add) % MOD;
    div *= 10;
  }
  max = N - (div - 1);
  add = (((1 + max) * max) % MOD) * INV % MOD;
  ans = (ans + add) % MOD;
  printf("%lld\n", ans);
  return 0;
}
