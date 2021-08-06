// mapがつかえないのでだめ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MOD 1000000007
#define INF 1000000009
typedef long long ll;

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  int c[300001];
  rep(i, 0, n) scanf("%d", &c[i]);
  int color[1000000001] = {0};
  int max = 0, colors = 0;
  rep(i, 0, n) {
    int l = i - k;
    if (!color[c[i]]) {
      color[c[i]]++;
      colors++;
    }
    if (l >= 0) {
      color[c[l]]--;
      if (!color[c[l]]) {
        colors--;
      }
    }
    max = max(max, colors);
  }
  printf("%d\n", max);
  return 0;
}
