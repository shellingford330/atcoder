#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
#define MAX 200001
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int e[2 * MAX][2];
int acs(const void *a, const void **b) { 
  if(e[*(int*)a][0] - e[*(int*)b][0] == 0) {
    return e[*(int*)a][1] - e[*(int*)b][1];
  }
  return e[*(int*)a][0] - e[*(int*)b][0];
} /* 1,2,3,4.. */

int main(void) {
  int n, w, s, t, p;
  scanf("%d %d", &n, &w);

  /* いもす法 */
  long long liter[MAX] = {0};
  rep(i, 0, n) {
    scanf("%d %d %d", &s, &t, &p);
    liter[s] += p, liter[t] += -p;
  }

  // 累積和
  long long sum = 0;
  rep(i, 0, MAX) {
    sum += liter[i];
    if (sum > w) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
  

  /* シミュレーション */
  // rep(i, 0, n) {
  //   scanf("%d %d %d", &s, &t, &p);
  //   e[2*i][0] = s; e[2*i][1] = p;
  //   e[2*i+1][0] = t; e[2*i+1][1] = -p;
  // }
  
  // int idx[2*n];
  // rep(i, 0, 2*n) idx[i] = i;
  // qsort(idx, 2*n, sizeof(int), acs);

  // long long crr = 0;
  // rep(i, 0, 2 * n) {
  //   crr += e[idx[i]][1];
  //   if (crr > w) {
  //     printf("No\n");
  //     return 0;
  //   }
  // }
  // printf("Yes\n");
  // return 0;
}
