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

int s(int a, int b) {
  return 4*a*b + 3*a + 3*b;
}

int main(void) {
  int N, S[21];
  scanf("%d", &N);
  rep(i, 0, N) scanf("%d", &S[i]);
  int ok[1001] = {0};
  rep(a, 1, 150) {
    rep(b, 1, 150) {
      if (s(a, b) > 1000) continue;
      ok[s(a,b)] = 1;
    }
  }
  int ans = 0;
  rep(i, 0, N) {
    if (!ok[S[i]]) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
