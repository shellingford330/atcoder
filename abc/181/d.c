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
#define MAX 200001
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
  char s[MAX];
  scanf("%s", s);

  int len = strlen(s);

  // 1桁の場合
  if (len == 1) {
    int num = (int)(s[0] - '0');
    if (num % 8 == 0) printf("Yes\n");
    else printf("No\n");
    return 0;
  }

  // 2桁の場合
  if (len == 2) {
    int num1 = (int)(s[1] - '0') * 10 + (int)(s[0] - '0');
    int num2 = (int)(s[0] - '0') * 10 + (int)(s[1] - '0');
    if (num1 % 8 == 0 || num2 % 8 == 0) printf("Yes\n");
    else printf("No\n");
    return 0;
  }

  // 3桁の場合
  int num_count[10] = {0};
  rep(i, 0, len) {
    int num = (int)(s[i] - '0');
    num_count[num]++;
  }
  
  for (int i = 112; i < 1000; i += 8) {
    int h = i / 100;
    int t = i / 10 % 10;
    int o = i % 10;
    num_count[h]--; num_count[t]--; num_count[o]--;
    if (num_count[h] >= 0 && num_count[t] >= 0 && num_count[o] >= 0) {
      printf("Yes\n");
      return 0;
    }
    num_count[h]++; num_count[t]++; num_count[o]++;
  }
  printf("No\n");
  return 0;
}
