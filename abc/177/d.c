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
#define MAX 200005
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int size[MAX] = {0};
int parent[MAX];
int a[MAX], b[MAX];

int root(int x) {
  if (x == parent[x]) return x;
  return parent[x] = root(parent[x]);
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  rep(i, 0, m) scanf("%d %d", &a[i], &b[i]);

  rep(i ,1, n+1) parent[i] = i;

  rep(i ,0, m) parent[root(a[i])] = root(b[i]);
  rep(i, 1, n+1) size[root(i)]++;

  int max = 0;
  rep(i, 1, n+1) max = max(max, size[i]);
  printf("%d\n", max); 
  return 0;
}
