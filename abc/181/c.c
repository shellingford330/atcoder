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
#define MAX 100001
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
  int n;
  scanf("%d", &n);
  double x[101], y[101];
  rep(i, 0, n) scanf("%lf %lf", &x[i], &y[i]);

  rep(i1, 0, n) {
    rep(i2, 0, n) {
      int ok = 0;
      rep(i3, 0, n) {
        if (i1 == i2 || i2 == i3 || i1 == i3) continue;
        if (x[i3] * (y[i2] - y[i1]) == (x[i2] - x[i1]) * (y[i3] - y[i1]) + x[i1] * (y[i2] - y[i1]))
          ok = 1;
      }
      if (ok) {
        printf("Yes\n");
        return 0;
      }
    }
  }

  printf("No\n");
  return 0;
}
