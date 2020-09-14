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
#define MAX 1000005
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

lli Gcd(lli x, lli y)
{
  if (y == 0) return x;
  return Gcd(y, x % y);
}

int main(void) {
  int n;
  int a[MAX], c[MAX] = {0};
  scanf("%d", &n);
  rep(i, 0, n) {
    scanf("%d", &a[i]);
    c[a[i]]++;
  }
  
  int pairwise = 1;
  rep(i, 2, MAX) {
    int cnt = 0;
    for (int j = i; j < MAX; j += i) {
      cnt += c[j];
    }
    if (cnt > 1) pairwise = 0;
  }
  if (pairwise) {
    printf("pairwise coprime");
    return 0;
  }

  int g = 0;
  rep(i, 0, n) g = Gcd(g, a[i]);
  if (g == 1) {
    printf("setwise coprime");
    return 0;
  }

  printf("not coprime");
  return 0;
}

