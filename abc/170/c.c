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
  int x, n, t;
  int p[102] = {0};
  scanf("%d %d", &x, &n);
  rep(i, 0, n) {
    scanf("%d", &t);
    p[t] = 1;
  }

  int min = INF, ans = INF;
  rep(i, 0, 102) {
    if (p[i]) continue;
    if (abs(i - x) > min) continue;
    if (abs(i - x) < min) ans = i;
    else ans = min(i, ans);
    min = abs(i - x);
  }
  printf("%d\n", ans);
  return 0;
}
