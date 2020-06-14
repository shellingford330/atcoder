#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int acs(const void *x, const void *y) { 
  return *(int*)x - *(int*)y;
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
	int n, m;
	scanf("%d %d", &n, &m);
	int h[MAX], a[MAX], b[MAX];
	rep(i, 1, n+1) scanf("%d", &h[i]);
	rep(i, 0, m) scanf("%d %d", &a[i], &b[i]);

	int maxh[MAX] = {0};
	rep(i, 0, m) {
		maxh[a[i]] = max(h[b[i]], maxh[a[i]]);
		maxh[b[i]] = max(h[a[i]], maxh[b[i]]);
	}
	int ans = 0;
	rep(i, 1, n+1) if (maxh[i] < h[i]) ans++;
	printf("%d\n", ans);
  return 0;
}
