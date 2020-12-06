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

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int next_permutation(int *arr, int len) {
  int l = len-2, r = len-1;
  while (l >= 0 && arr[l] >= arr[l+1]) l--;
  if (l < 0) return 0;
  
  while(arr[l] >= arr[r]) r--;
  swap(&arr[l], &arr[r]);
  // reverse
  for (l++, r = len-1; l < r; l++, r--) swap(&arr[l], &arr[r]);
  return 1;
}

int t[9][9];
int idx[9];

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  rep(i, 0, n) rep(j, 0, n) scanf("%d", &t[i][j]);
  rep(i, 0, n) idx[i] = i;
  int ans = 0;
  do {
    int time = 0;
    rep(i, 0, n) time += t[idx[i]][idx[(i+1)%n]];
    if (time == k) ans++;
  } while(next_permutation(idx, n-1));
  printf("%d\n", ans);
  return 0;
}