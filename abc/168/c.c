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
  long double a, b, h, m;
  scanf("%Lf %Lf %Lf %Lf", &a, &b, &h, &m);

  long double max = max(h * 30.0 + m / 60.0 * 30.0, m * 6.0);
  long double min = min(h * 30.0 + m / 60.0 * 30.0, m * 6.0);
  long double rad = (max - min) / 180.0 * M_PI;
  long double c = a * a + b * b - 2.0 * a * b * cosl(rad);
  printf("%.10Lf\n", sqrtl(c));
  return 0;
}
