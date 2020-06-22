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
  int N, Q, A;
  int a[MAX] = {0}, B[MAX], C[MAX];
  scanf("%d", &N);
  rep(ni, 0, N) {
    scanf("%d", &A);
    a[A]++;
  }
  scanf("%d", &Q);
  rep(qi, 0, Q) scanf("%d %d", &B[qi], &C[qi]);

  long long int sum = 0;
  rep(ni, 0, MAX) sum += a[ni] * ni;

  rep(qi, 0, Q) {
    int add = C[qi] - B[qi];
    sum += add * a[B[qi]];  // 増加分 × 個数
    a[C[qi]] += a[B[qi]]; a[B[qi]] = 0;
    printf("%lld\n", sum);
  }
  return 0;
}
