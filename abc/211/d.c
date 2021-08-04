#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

/* graph */ 

typedef struct list {
  int node;
  struct list *next;
} list;

list* graph[MAX];

void init_graph(void) {
  for (int i = 0; i < MAX; i++)
    graph[i] = NULL;
}

void add_edge(int node1, int node2) {
  list* new1 = (list*)malloc(sizeof(list*));
  new1->node = node2;
  new1->next = graph[node1];
  graph[node1] = new1;

  list* new2 = (list*)malloc(sizeof(list*));
  new2->node = node1;
  new2->next = graph[node2];
  graph[node2] = new2;
}

/* queue */ 

typedef struct {
  int front;
  int rear;
  int data[MAX][2];
} queue;

queue q;

void init(queue *q) {
  q->front = q->rear = 0;
}

bool is_empty(queue *q) {
  return q->front == q->rear;
}

bool is_full(queue *q) {
  return (q->front - 1 == q->rear) || (q->front == 0 && q->rear == MAX - 1);
}

void pop(queue *q) {
  if ( is_empty(q) ) {
    printf("UnderFlow\n");
    exit(1);
  } else {
    q->front++;
    if (q->front == MAX)
      q->front = 0;
  }
}

void push(queue *q, int node, int dist) {
  if ( is_full(q) ) {
    printf("OverFlow\n");
    exit(1);
  } else {
    q->data[q->rear][0] = node;
    q->data[q->rear][1] = dist;
    q->rear++;
    if ( q->rear == MAX )
      q->rear = 0;
  }
}

int dist[MAX];
lli cnt[MAX] = {0};

void bfs() {
  init(&q);
  push(&q, 1, 0);
  while (!is_empty(&q)) {
    int n = q.data[q.front][0];
    pop(&q);
    for (list *g = graph[n]; g != NULL; g = g->next) {
      int nn = g->node;
      if (dist[nn] == -1) {
        dist[nn] = dist[n] + 1;
        cnt[nn] = cnt[n];
        push(&q, nn, 0);
      } else if (dist[nn] == dist[n] + 1) {
        cnt[nn] = (cnt[nn] + cnt[n]) % MOD;
      }
    }
  }
}

int main(void) {
  int n, m, a, b;
  scanf("%d %d", &n, &m);
  init_graph();
  rep(i, 0, m) {
    scanf("%d %d", &a, &b);
    add_edge(a, b);
  }
  rep(i, 0, MAX) dist[i] = -1;
  dist[1] = 0; cnt[1] = 1;
  bfs();
  printf("%lld\n", cnt[n]);
  return 0;
}
