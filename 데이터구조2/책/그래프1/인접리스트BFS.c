#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10
#define MAX_VERTICES 50

int visited[MAX_VERTICES];
typedef int element;

typedef struct{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void queue_init(QueueType *q){
    q->front = q->rear = 0;
}

int is_empty(QueueType *q){
    return (q->front == q->rear);
}

int is_full(QueueType *q){
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item){
    if(is_full(q)){
        error("[enqueue]큐가 포화상태입니다.");
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        error("[dequeue]큐가 포화상태입니다.");
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    
    return q->queue[q->front];
}

typedef struct GraphNode{
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType{
    int n;
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

void init(GraphType *g){
    g->n = 0;

    for(int v=0; v<MAX_VERTICES; v++){
        g->adj_list[v] = NULL;
    }
}

void insert_vertex(GraphType *g, int v){
    if(((g->n)+1) > MAX_VERTICES){
        fprintf(stderr, "[insert_vertex]그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int u, int v){
    GraphNode *node = (GraphNode*)malloc(sizeof(GraphNode));

    if(u >= g->n || v >= g->n){
        fprintf(stderr, "[insert_edge]그래프: 정점 번호 오류");
        return;
    }
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

/////////////////////////////////////
void bfs_list(GraphType *g, int v){
    GraphNode *w;
    QueueType q;

    init(&q);

    visited[v] = TRUE;

    printf("%d 방문 -> ", v);
    enqueue(&q, v);

    while (!is_empty(&q)){
        v = dequeue(&q);

        for(w=g->adj_list[v]; w; w=w->link){
            if(!visited[w->vertex]){
                visited[w->vertex] = TRUE;
                printf("%d 방문 -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
    
}
/////////////////////////////////////