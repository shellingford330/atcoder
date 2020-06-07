#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int acs(const void *a, const void *b) { 
  if (*(long long int*)a - *(long long int*)b > 0)
    return 1;
  else if(*(long long int*)a - *(long long int*)b < 0)
    return -1;
  else 
    return 0;
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
#define INF 1000000000000000000

typedef long long int lli;

int main(void) {
  int n;
  long long int sum = 1;
  long long int a[MAX];

  scanf("%d", &n);
  rep(i, 0, n) scanf("%lld", &a[i]);
  rep(i, 0, n) {
    if (sum == 0) {
      sum = 0;
      break;
    }
    if (a[i] > INF / sum) {
      sum = -1;
      break;
    }
    sum *= a[i];
  }

  printf("%lld\n", sum);
  return 0;
}
