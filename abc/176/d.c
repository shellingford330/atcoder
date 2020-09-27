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
#define MAX 1005
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

typedef struct {
  int front;
  int rear;
  int data[20000000][2];
} queue;

queue que;

void initQueue(queue *p) {
  p->front = p->rear = 0;
}

bool emptyQueue(queue *p) {
  return p->front == p->rear;
}

bool fullQueue(queue *p) {
  return (p->front - 1 == p->rear) || (p->front == 0 && p->rear == 20000000 - 1);
}

void popLeft(queue *p) {
  if ( emptyQueue(p) ) {
    printf("UnderFlow\n");
    exit(1);
  } else {
    p->front++;
    if (p->front == 20000000)
      p->front = 0;
  }
}

void pop(queue *p) {
  if ( emptyQueue(p) ) {
    printf("UnderFlow\n");
    exit(1);
  } else {
    p->rear--;
    if (p->rear == -1)
      p->rear = 20000000 - 1;
  }
}

void push(queue *p, int y, int x) {
  if ( fullQueue(p) ) {
    printf("OverFlow\n");
    exit(1);
  } else {
    p->data[p->rear][0] = y;
    p->data[p->rear][1] = x;
    p->rear++;
    if ( p->rear == 20000000 )
      p->rear = 0;
  }
}

void pushLeft(queue *p, int y, int x) {
  if ( fullQueue(p) ) {
    printf("OverFlow\n");
    exit(1);
  } else {
    p->front--;
    if ( p->front == -1 )
      p->front = 20000000 - 1;
    p->data[p->front][0] = y;
    p->data[p->front][1] = x;
  }
}


int H, W, Ch, Cw, Dh, Dw;

char S[MAX][MAX];

int main(void) {
  scanf("%d %d", &H, &W);
  scanf("%d %d", &Ch, &Cw);
  scanf("%d %d", &Dh, &Dw);

  rep(i, 0, H) scanf("%s", S[i]);

  int dist[MAX][MAX];
  rep(i, 0, MAX) rep(j, 0, MAX) dist[i][j] = INF;


  int ax[4] = {0, 1, 0, -1};
  int ay[4] = {1, 0, -1, 0};

  initQueue(&que);
  pushLeft(&que, Ch-1, Cw-1);
  dist[Ch-1][Cw-1] = 0;
  while ( !emptyQueue(&que) ) {
    int y = que.data[que.front][0];
    int x = que.data[que.front][1];
    popLeft(&que);
    if ( y == Dh-1 && x == Dw-1 ) {
      printf("%d\n", dist[y][x]);
      return 0;
    }
    rep(i, 0, 4) {
      int ny = y + ay[i];
      int nx = x + ax[i];
      if ( ny < 0 || H <= ny ) continue;
      if ( nx < 0 || W <= nx ) continue;
      if ( S[ny][nx] == '#' ) continue;
      if ( dist[ny][nx] <= dist[y][x] ) continue;
      dist[ny][nx] = dist[y][x];
      pushLeft(&que, ny, nx); 
    }

    rep(by, -2, 3) rep(bx, -2, 3) {
      int ny = y + by;
      int nx = x + bx;
      if ( ny < 0 || H <= ny ) continue;
      if ( nx < 0 || W <= nx ) continue;
      if ( S[ny][nx] == '#' ) continue;
      if ( dist[ny][nx] <= dist[y][x] + 1 ) continue;
      dist[ny][nx] = dist[y][x] + 1;
      push(&que, ny, nx);
    }
  }
  printf("-1\n");
  return 0;
}
