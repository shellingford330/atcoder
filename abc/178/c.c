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

// 繰り返し２乗法
lli PowMod(lli n, lli pow, lli mod) {
	if (pow == 0) return 1;
	if (pow % 2 == 0) {
		lli tmp = PowMod(n, pow / 2, mod);
		return tmp * tmp % mod;
	}
	return n * PowMod(n, pow - 1, mod) % mod;
}

int main(void) {
  lli n;
  scanf("%lld", &n);

  lli ans = PowMod(10, n, MOD) - PowMod(9, n, MOD) - PowMod(9, n, MOD) + PowMod(8, n, MOD);
  ans %= MOD;
  ans = (ans + MOD) % MOD;
  printf("%lld\n", ans);
  return 0;
}
