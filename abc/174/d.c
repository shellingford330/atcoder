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
  int N;
  char c[MAX];
  scanf("%d %s", &N, c);

  int cnt = 0;
  int f = 0;
  int r = N - 1;
  while (1) {
    while (f < N && c[f] == 'R') f++;
    while (r >= 0 && c[r] == 'W') r--;
    if (f > r) break;
    c[f] = 'R';
    c[r] = 'W';
    cnt++; 
  }
  printf("%d\n", cnt);
  return 0;
}
