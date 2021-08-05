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
  int n, m;
  scanf("%d %d", &n, &m);
  int a[MAX], b[MAX];
  rep(i, 0, n) scanf("%d", &a[i]);
  rep(i, 0, m) scanf("%d", &b[i]);
  
  qsort(b, m, sizeof(int), acs);

  int ans = INF;
  rep(i, 0, n) {
    int l = 0;
    int r = m - 1;
    while (r - l > 1) {
      int mid = (r + l) / 2;
      if (a[i] - b[mid] == 0) {
        printf("0\n");
        return 0;
      }
      if (a[i] - b[mid] > 0) {
        l = mid;
        continue;
      }
      r = mid;
    }
    ans = min(ans, min(abs(a[i] - b [l]), abs(a[i] - b[r])));
  }
  printf("%d\n", ans);
  return 0;
}
