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
#define MAX 101
#define MOD 1000000007
#define INF 1000000009
typedef long long ll;

int main(void) {
  int n;
  scanf("%d", &n);
  int a[MAX];
  rep(i, 0, n) scanf("%d", &a[i]);

  int ans = 0, max = 0;
  rep(k, 2, 1001) {
    int degree = 0;
    rep(ai, 0, n) {
      if(a[ai] % k == 0) degree++;
    }
    if (degree > max) {
      ans = k;
      max = degree;
    }
  }
  printf("%d\n", ans);
  return 0;
}

