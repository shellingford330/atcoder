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

int color[MAX] = {0};

void dfs(int parent, int now) {
  color[now] = !color[parent];
  for (list* child = graph[now]; child != NULL; child = child->next) {
    if (child->node == parent) continue;
    dfs(now, child->node);
  }
}

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  int a, b;
  init_graph();
  rep(i, 0, n-1) {
    scanf("%d %d", &a, &b);
    add_edge(a, b);
  }
  dfs(0, 1);
  int c, d;
  rep(i, 0, q) {
    scanf("%d %d", &c, &d);
    printf(color[c] == color[d] ? "Town\n" : "Road\n");
  }
  return 0;
}
