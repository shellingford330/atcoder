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
typedef long long lli;

int main(void) {
  long long int a;
  double b;
  scanf("%lld %lf", &a, &b);
  printf("%f\n", b * 100);

  /* doubleからint型へのキャスト時は、誤差を加味しなければいけない */
  /* 9.9999... → 9 */
  long long sum = (a * (int)(b * 100 + 0.5)) / 100; 
  printf("%lld\n", sum);
  return 0;
}
