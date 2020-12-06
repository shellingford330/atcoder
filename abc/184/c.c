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
  int r1, c1, r2, c2;
  scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

  /* 3手以内で必ず到達可能 */
  // 0手で到達する場合
  if (r1 == r2 && c1 == c2) {
    printf("0\n");
    return 0;
  }
  // 1手で到達する場合
  if (
    r1 + c1 == r2 + c2 ||
    r1 - c1 == r2 - c2 ||
    abs(r1 - r2) + abs(c1 - c2) <= 3
  ) {
    printf("1\n");
    return 0;
  }
  // 2手で到達する場合
  if (
    ((r1 + c1) - (r2 + c2)) % 2 == 0 ||
    abs(r1 - r2) + abs(c1 - c2) <= 6 ||
    abs((r1 + c1) - (r2 + c2)) <= 3 ||
    abs((r1 - c1) - (r2 - c2)) <= 3
  ) {
    printf("2\n");
    return 0;
  }
  // 3手で到達する場合
  printf("3\n");
  return 0;
}
