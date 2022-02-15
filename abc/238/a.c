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
  int n;
  scanf("%d", &n);

  printf(pow(2, n) > pow(n, 2) ? "Yes" : "No");
  return 0;
}
