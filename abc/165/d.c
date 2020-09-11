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
#define MAX 1000000000001
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
	long long A, B, N;
	scanf("%lld %lld %lld", &A, &B, &N);

	long long max = 0;
	for (long long x = 1; x <= N; x++) {
		long long tmp = A * x / B - A * (x / B);
		max = max(tmp, max);
	}
	printf("%lld\n", max);
  return 0;
}
