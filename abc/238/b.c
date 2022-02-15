#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 100001
#define MOD 1000000007
#define INF 1000000009

int main(void) {
  int n, a[360];
  scanf("%d", &n);
  rep(i, 0, n) scanf("%d", &a[i]);

  int sum = 0;
  int theta[361] = {0};
  theta[0] = 1; theta[360] = 1;
  rep(i, 0, n) {
    sum = (sum + a[n-i-1]) % 360;
    theta[sum] = 1;
  }
  
  int pre = 0;
  int ans = 0;
  rep(i, 1, 361) {
    if (theta[i]) {
      ans = max(i - pre, ans);
      pre = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
