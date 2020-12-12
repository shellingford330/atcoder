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
#define MAX 500001
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
  // 光: 1, ブロック: 2, 光がない: 0
  int h_mass[1501][1501] = {0};
  int w_mass[1501][1501] = {0};
  int h, w, n, m;
  scanf("%d %d %d %d", &h, &w, &n, &m);

  int a[MAX], b[MAX];
  rep(i, 0, n) scanf("%d %d", &a[i], &b[i]);
  int c, d;
  rep(i, 0, m) {
    scanf("%d %d", &c, &d);
    h_mass[c][d] = w_mass[c][d] = 2;
  }

  rep(i, 0, n) {
    // 縦
    if (h_mass[a[i]][b[i]] == 0) {
      h_mass[a[i]][b[i]] = 1;
      for (int hi = a[i]; hi > 0; hi--) {
        if (h_mass[hi][b[i]] == 2) break;
        h_mass[hi][b[i]] = 1;
      }
      for (int hi = a[i]; hi <= h; hi++) {
        if (h_mass[hi][b[i]] == 2) break;
        h_mass[hi][b[i]] = 1;
      }
    }

    // 横
    if (w_mass[a[i]][b[i]] == 0) {
      w_mass[a[i]][b[i]] = 1;
      for (int wi = b[i]; wi > 0; wi--) {
        if (w_mass[a[i]][wi] == 2) break;
        w_mass[a[i]][wi] = 1;
      }
      for (int wi = b[i]; wi <= w; wi++) {
        if (w_mass[a[i]][wi] == 2) break;
        w_mass[a[i]][wi] = 1;
      }
    }
  }

  int ans = 0;
  rep(hi, 1, h+1) {
    rep(wi, 1, w+1) {
      if (h_mass[hi][wi] == 1 || w_mass[hi][wi] == 1) 
        ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
