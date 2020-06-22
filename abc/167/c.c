#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int acs(const void *a, const void *b) { 
  return *(int*)a - *(int*)b;
} /* 1,2,3,4.. */
int des(const void *a, const void *b) {
  return *(int*)b - *(int*)a;
} /* 8,7,6,5.. */
int cmp_char(const void *a, const void *b) { 
  return *(char*)a - *(char*)b;
} /* a,b,c,d.. */
int cmp_str(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
} /* aaa,aab.. */
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 15
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
  int n, m, x;
  scanf("%d %d %d", &n, &m, &x);
  int c[MAX], a[MAX][MAX];
  rep(i, 0, n) {
    scanf("%d", &c[i]);
    rep(j, 0, m) scanf("%d", &a[i][j]);
  }

  int ans = INF;
  for (int i = 0; i < (1 << n); i++) {
    int money = 0;
    int sum_a[MAX] = {0};
    for (int j = 0; j < n; j++) {
      int buy = (i >> j) & 1;
      money += c[j] * buy;
      for (int k = 0; k < m; k++) sum_a[k] += a[j][k] * buy;
    }
    int ok = 1;
    for (int k = 0; k < m; k++) {
      if (sum_a[k] >= x) continue;
      ok = 0;
      break;
    }
    if (ok) ans = min(money, ans);
  }
  printf("%d\n", ans == INF ? -1 : ans);
  return 0;
}
