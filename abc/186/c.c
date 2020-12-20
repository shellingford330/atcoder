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

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int ok = 1;
    int ten = i;

    while (ten != 0) {
      if (ten % 10 == 7) {
        ok = 0;
        break;
      }
      ten /= 10;
    }

    int eight = i;
    while (eight != 0) {
      if (eight % 8 == 7) {
        ok = 0;
        break;
      }
      eight /= 8;
    }
    if (ok) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
