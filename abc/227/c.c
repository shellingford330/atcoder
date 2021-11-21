#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (long long i = l; i < r; i++)
#define MAX 100001
#define MOD 1000000007
#define INF 1000000009

int main(void) {
  long long n;
  scanf("%lld", &n);
  long long ans = 0;
  for (long long i=1; i*i*i <= n; i++) {
    for (long long j=i; i*j*j <= n; j++) {
      long long c = n / (i*j) - j + 1;
      ans += max(c, 0);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
