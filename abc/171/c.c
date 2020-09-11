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
	long long n;
	scanf("%lld", &n);

	int cnt = 0;
	long long alp[20] = {0};
	while (n / 26 != 0) {
		alp[cnt++] = n % 26;
		n /= 26;
	}
	alp[cnt++] = n % 26;
	for (int i = cnt-1; i >= 0; i--) printf("%c", (char)(alp[i] + 'a'));
	printf("\n");
  return 0;
}
