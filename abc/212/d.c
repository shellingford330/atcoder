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

// 優先度付きキュー Priority Queue

typedef struct {
  long long int pri;
  long long int val;
} queue;

queue pq[MAX];
int pq_size = 0; // 最大要素
long long int sum[MAX] = {0};
int qi;

void swap(queue *a, queue *b) {
  queue tmp = *a;
  *a = *b;
  *b = tmp; 
}

void add(long long int pri, long long int val) {
  // 1. 末尾に新しい要素を入れる
  int node = ++pq_size;
  queue new = { .pri = pri, .val = val};
  pq[pq_size] = new;

  // 2. 根か親要素よりも小さくなるまでボトムアップする
  while (node > 1 && pq[node].pri + sum[val] - sum[pq[node].val] < pq[node / 2].pri + sum[val] - sum[pq[node / 2].val]) {
    swap(&pq[node], &pq[node / 2]);
    node /= 2;
  }
  return;
}

queue get(void) {
  queue root = pq[1];
  // 1. 末尾の要素を根に持ってくる
  pq[1] = pq[pq_size--];

  // 2. ボトムか子要素よりも大きくなるまでトップダウンする
  int node = 1, lrg;
  while (node * 2 <= pq_size) {
    if (node * 2 == pq_size) lrg = node * 2; // 子要素が一つしかない場合
    else if (pq[node*2].pri + sum[qi] - sum[pq[node*2].val] < pq[node*2+1].pri + sum[qi] - sum[pq[node*2+1].val]) lrg = node * 2; // 左子要素のほうが大きい場合
    else lrg = node * 2 + 1; // 右子要素のほうが大きい場合

    if (pq[node].pri + sum[qi] - sum[pq[node].val] > pq[lrg].pri + sum[qi] - sum[pq[lrg].val]) {
      swap(&pq[node], &pq[lrg]);
      node = lrg;
    } else break;
  }
  return root;
}


int main(void) {
  int q;
  scanf("%d", &q);

  // char *input;
  int o;
  long long int x;
  rep(qi, 1, q+1) {
    scanf("%d", &o);
    switch (o) {
      case 1:
        scanf("%lld", &x);
        sum[qi] = sum[qi-1];
        add(x, qi);
        break;
      case 2:
        scanf("%lld", &x);
        sum[qi] = sum[qi-1] + x;
        break;
      case 3:
        sum[qi] = sum[qi-1];
        queue root = get();
        printf("%lld\n", root.pri + sum[qi] - sum[root.val]);
        break;
      default:
        printf("unexpected error");
        exit(1);
    }
  }
  return 0;
}
