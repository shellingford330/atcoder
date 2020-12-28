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
#define rep(i, n) for (int i = 0; i < n; i++)
#define MAX 200005
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  int a[MAX];
  a[0] = 0;
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  a[m+1] = n + 1; 

  qsort(a, m+2, sizeof(int), acs);

  int k = n;
  for (int i = 1; i <= m+1; i++) {
    int width = a[i] - a[i-1] - 1;
    if (width == 0) continue;
    k = min(k, width);
  }

  int ans = 0;
  for (int i = 1; i <= m+1; i++) {
    int width = a[i] - a[i-1] - 1;
    if (width == 0) continue;
    ans += (width - 1) / k + 1;
  }
  printf("%d\n", ans);
  return 0;
}
