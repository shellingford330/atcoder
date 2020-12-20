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
#define MAX 200005
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
  long long n, a[MAX];
  scanf("%lld", &n);
  rep(i, 0, n) scanf("%lld", &a[i]);

  qsort(a, n, sizeof(long long), des);

  long long sum[MAX] = {0};
  for (int i = n-1; i >= 0; i--) {
    sum[i] = sum[i+1] + a[i];
  }

  long long ans = 0;
  rep(i, 0, n-1) {
    ans += (n - i - 1) * a[i] - sum[i+1];
  }
  printf("%lld\n", ans);
  return 0;
}
