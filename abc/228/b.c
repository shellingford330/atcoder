#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 100001
#define MOD 1000000007
#define INF 1000000009
typedef long long ll;

int main(void) {
  int n, x;
  scanf("%d %d", &n, &x);
  int a[MAX];
  rep(i, 1, n+1) scanf("%d", &a[i]);
  int know[MAX] = {0};
  int count = 0;
  while (!know[x]) {
    know[x] = 1;
    count++;
    x = a[x];
  }
  printf("%d\n", count);
  return 0;
}
