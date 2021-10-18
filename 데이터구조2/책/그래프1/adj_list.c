#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

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

void insert_edge(GraphType *g, int u, int v){                   // 그래프 포인터, 연결점, [이름]
    GraphNode *node = (GraphNode*)malloc(sizeof(GraphNode));    // 동적생성

    if(u >= g->n || v >= g->n){                                 // 최대 5개 다 -> 0~4, 5오류
        fprintf(stderr, "[insert_edge]그래프: 정점 번호 오류");
        return;
    }
    node->vertex = v;               // node 포인터의 vertex = v; [이름]
    node->link = g->adj_list[u];    // node->link = g->adj_list[연결점] 이름이 0이야 0 -> 3  v = 0, u = 3
    g->adj_list[u] = node;
}

void print_adj_list(GraphType *g){
    for(int i=0; i<g->n; i++){
        GraphNode *p = g->adj_list[i];
        printf("정점 %d의 인접 리스트 ",i);

        while(p != NULL){
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

int main(void){
    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    init(g);

    for(int i=0; i<4; i++){
        insert_vertex(g, i);
    }

    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);

    print_adj_list(g);

    free(g);

    return 0;
}