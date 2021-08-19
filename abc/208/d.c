#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 401
#define MOD 1000000007
#define INF 1000000009
typedef long long ll;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  int f[MAX][MAX][MAX];
  rep(i, 0, n+1) rep(j, 0, n+1) {
    if (i == j) f[i][j][0] = 0;
    else f[i][j][0] = INF;
  }
  rep(i, 0, m) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    f[a][b][0] = c;
  }
  ll ans = 0;
  rep(k, 1, n+1) rep(j, 1, n+1) rep(i, 1, n+1) {
    f[i][j][k] = min(f[i][j][k-1], f[i][k][k-1] + f[k][j][k-1]);
    if (f[i][j][k] != INF) ans += f[i][j][k];
  }
  printf("%lld\n", ans);
  return 0;
}
