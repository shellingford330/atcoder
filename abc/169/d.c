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
  int N;
  char S[4005];
  scanf("%d %s", &N, S);

  int R[4005] = {0}, G[4005] = {0}, B[4005] = {0};
  for ( int i = N-1; i >= 0; i--) {
    R[i] = R[i+1] + (S[i] == 'R');
    G[i] = G[i+1] + (S[i] == 'G');
    B[i] = B[i+1] + (S[i] == 'B');
  } 
  rep(i, 0, N) {
    if ( )
    rep(j, 0, N) {

    }
  } 
  return 0;
}
