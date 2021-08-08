#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 200001
#define MOD 1000000007
#define INF 1000000009
typedef long long ll;

int acs(const void *a, const void *b) { 
  return *(int*)a - *(int*)b;
} /* 1,2,3,4.. */

int main(void) {
  int n;
  scanf("%d", &n);
  int c[MAX];
  rep(i, 0, n) scanf("%d", &c[i]);

  qsort(c, n, sizeof(int), acs);

  ll ans = 1;
  rep(i, 0, n) ans = ans * (c[i] - i) % MOD;
  printf("%lld\n", ans);
  return 0;
}
