#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 100001
#define MOD 1000000007
#define INF 1000000009

int main(void) {
  double x;
  scanf("%lf", &x);

  printf("%d\n", (int)round(x));
  return 0;
}
