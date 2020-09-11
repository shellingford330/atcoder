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
  char s[1001], t[1001];
  scanf("%s %s", s, t);

  int sl = strlen(s);
  int tl = strlen(t);

  int max = 0;
  for (int si = 0; si <= sl - tl; si++) {
    int tmp = si;
    int count = 0;
    for (int ti = 0; ti < tl; ti++) {
      if (s[tmp] == t[ti]) count++;
      tmp++;
    }
    max = max(max, count);
  }
  printf("%d\n", tl - max);
  return 0;
}
