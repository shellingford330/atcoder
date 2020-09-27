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
#define MAX 300005
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
  int H, W, M;
  scanf("%d %d %d", &H, &W, &M);

  int hn[MAX] = {0}, wn[MAX] = {0};
  int h[MAX], w[MAX];
  
  rep(i, 0, M) {
    scanf("%d %d", &h[i], &w[i]);
    hn[h[i]]++; wn[w[i]]++;
  }

  int maxhn = 0, maxwn = 0;
  for (int i = 1; i <= H; i++) maxhn = max(maxhn, hn[i]);
  for (int i = 1; i <= W; i++) maxwn = max(maxwn, wn[i]);
  
  int maxhc = 0, maxwc = 0;
  for (int i = 1; i <= H; i++) if (hn[i] == maxhn) maxhc++;
  for (int i = 1; i <= W; i++) if (wn[i] == maxwn) maxwc++;
  
  int mc = 0;
  rep(i, 0, M) if (hn[h[i]] == maxhn && wn[w[i]] == maxwn)
    mc++;

  printf("%d\n", maxhn + maxwn - (maxhc * maxwc == mc));
  return 0;
}
