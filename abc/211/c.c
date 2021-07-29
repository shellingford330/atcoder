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
  char s[MAX];
  scanf("%s", s);

  int n = strlen(s);
  char *chokudai = "chokudai";
  lli dp[MAX][9] = {0};
  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int si = 1; si <= n; si++) {
    for (int i = 1; i <= 8; i++) {
      if (s[si-1] == chokudai[i-1]) {
        dp[si][i] = (dp[si-1][i] + dp[si-1][i-1]) % MOD;
      } else {
        dp[si][i] = dp[si-1][i];
      }
    }
  }
  printf("%lld\n", dp[n][8]);
  return 0;
}
