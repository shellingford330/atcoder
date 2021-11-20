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
  int s, t, x;
  scanf("%d %d %d", &s, &t, &x);

  if (s < t) {
    if (x >= s && x < t) {
      printf("Yes");
    } else {
      printf("No");
    }
  } else {
    if (x >= s || x < t ) {
      printf("Yes");
    } else {
      printf("No");
    }
  }
  return 0;
}
