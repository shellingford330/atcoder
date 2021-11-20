#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 100001
#define MOD 1000000007
#define INF 1000000009
typedef long long ll;

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  int score[MAX];
  int nums[1201] = {0};
  int a, b, c;
  rep(i, 0, n) {
    scanf("%d %d %d", &a, &b, &c);
    score[i] = a + b + c;
    nums[a+b+c]++;
  }
  rep(i, 0, n) {
    int max = score[i] + 300;
    int ranking = 1;
    rep(exp, max+1, 1201) {
      ranking += nums[exp];
    }
    printf(ranking <= k ? "Yes\n" : "No\n");
  }
  return 0;
}
