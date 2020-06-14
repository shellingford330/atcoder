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
#define pow5(i) i * i * i * i * i
#define MAX 100001
#define MOD 1000000007
#define INF 1000000000
typedef long long int lli;

int main(void) {
  int x;
  scanf("%d", &x);
  int lim;
  rep(i, 1, 200) {
    if (pow5(i) - pow5(i-1) < INF) continue;
    lim = i;
    break;
  }
  printf("%d\n", lim);
  rep(i, -lim, lim) {
    rep(j, -lim, lim) {
      if (pow5(i) - pow5(j) == x) {
        printf("%d %d\n", i, j);
        goto exit;
      }
    }
  }
  exit:;
  return 0;
}
