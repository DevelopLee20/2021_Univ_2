#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 50

int visited[MAX_VERTICES] = {0,};
int visited1[MAX_VERTICES] = {0,};

typedef struct GraphNode{
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
    int v[MAX_VERTICES];
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

void init(GraphType *g){
    g->n = 0;
    for(int r=0; r<MAX_VERTICES; r++){
        for(int c=0; c<MAX_VERTICES; c++){
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType *g, int v){
    if (((g->n) + 1) > MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->v[g->n] = v;
    g->n++;
}

void print_adj_mat(GraphType *g){
    for(int i=0; i<g->n; i++){
        printf("%c ", g->v[i]);
        for(int j=0; j<g->n; j++){
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

// 무작위 그래프 발생
// 그래프 포인터, 노드의 개수, 정점의 개수
void rand_edge(GraphType *g, int num, int point){
    srand(time(NULL));

    while(num){
        int x = rand() % point;
        int y = rand() % point;
        
        if (x != y && g->adj_mat[x][y] + g->adj_mat[y][x] == 0){
            g->adj_mat[x][y] = 1;
            g->adj_mat[y][x] = 1;
            num--;
        }
    }
}

void dfs_mat(GraphType *g, int v){
    visited[v] = 1;
    printf("%c ", g->v[v]);
    for(int w=0; w<g->n; w++){
        if (g->adj_mat[v][w] && !visited[w]){
            dfs_mat(g, w);
        }
    }
}

void make_list(GraphType *g, int point){
    for(int i=point-1; i>-1; i--){
        for(int j=point-1; j>-1; j--){
            if(g->adj_mat[i][j] == 1){
                GraphNode *node = (GraphNode*)malloc(sizeof(GraphNode));
                node->vertex = j;
                node->link = g->adj_list[i];
                g->adj_list[i] = node;
            }
        }
    }
}

void dfs_list(GraphType *g, int v){
    GraphNode *w;
    visited1[v] = 1;
    printf("%c ", g->v[v]);
    for(w = g->adj_list[v]; w; w=w->link){
        if (!visited1[w->vertex]){
            dfs_list(g, w->vertex);
        }
    }
}

int main(void){
    int point, node;

    GraphType *g = (GraphType *)malloc(sizeof(GraphType));
    init(g);

    printf("정점의 개수는? ");
    scanf("%d", &point);
    fflush(stdin);
    printf("랜덤 연결 그래프 생성\n");
    printf("간선 수는? ");
    scanf("%d", &node);
    fflush(stdin);

    for(int i=65; i<65+point; i++){
        insert_vertex(g, i);
    }

    rand_edge(g, node, point);

    print_adj_mat(g);

    printf("mat DFS: ");
    dfs_mat(g, 0);
    printf("\n");

    make_list(g, point);
    printf("lst DFS: ");
    dfs_list(g, 0);


    free(g);

    return 0;
}