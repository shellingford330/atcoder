#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 100001
#define MOD 1000000007
#define INF 1000000009
typedef long long ll;

int main(void) {
  int n, k, a;
  scanf("%d %d %d", &n, &k, &a);

  int r = k % n;
  int ans = a + r - 1;
  if (ans <= 0) ans += n;
  else if (ans > n) ans -= n;
  printf("%d\n", ans);
  return 0;
}
