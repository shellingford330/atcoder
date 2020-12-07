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
#define MAX 200001
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
  int n, a[MAX];
  scanf("%d", &n);
  rep(i, 0, n) scanf("%d", &a[i]);

  lli kyori[MAX] = {0};
  rep(i, 0, n) kyori[i+1] = kyori[i] + a[i];

  lli max_kyori[MAX] = {0};
  rep(i, 0, n) max_kyori[i+1] = max(kyori[i+1], max_kyori[i]);

  lli ans = 0, p = 0;
  rep(i, 0, n) {
    ans = max(p + max_kyori[i+1], ans);
    p += kyori[i+1];
  }
  printf("%lld\n", ans);
  return 0;
}
