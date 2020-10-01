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
  int H, W, K;
  scanf("%d %d %d", &H, &W, &K);
  char c[10][10];
  rep(i, 0, H) scanf("%s", c[i]);

  int all = 0;
  rep(h, 0, H) rep(w, 0, W)
    if (c[h][w] == '#') all++;

  int comb = 0;
  for (int i = 0; i < (1 << H); i++) {
    for (int j = 0; j < (1 << W); j++) {
      int black = 0;
      for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
          if (((i >> h) & 1) || ((j >> w) & 1)) {
            if (c[h][w] == '#') black++;
          }
        }
      }
      if (all - black == K) comb++; 
    }
  }
  printf("%d\n", comb);
  return 0;
}
