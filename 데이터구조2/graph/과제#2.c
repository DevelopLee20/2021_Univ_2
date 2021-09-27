#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_VERTICES 50

char name_tag[50] = {'A','B','C','D','F','G','H','I','J'};
int visited[MAX_VERTICES];

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
    int v;
} GraphType;

// 그래프 초기화
void init(GraphType *g){
    g->n = 0;
    for (int r=0; r<MAX_VERTICES; r++){
        for (int c=0; c<MAX_VERTICES; c++){
            g->adj_mat[r][c] = 0;
        }
    }
}

// 정점 삽입 연산
void insert_vertex(GraphType *g, int v){
    if (((g->n)+1) > MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->v = v;
    g->n++;
}

// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다
int insert_edge(GraphType *g, int start, int end){
    if (start >= g->n || end >= g->n){
        fprintf(stderr, "그래프: 정점의 번호 오류");
        exit(1);
    }
    if (g->adj_mat[start][end] != 1){
        g->adj_mat[start][end] = 1;
        g->adj_mat[end][start] = 1;
        return 1;
    }
    return 0;
}

void print_adj_mat(GraphType* g){
    for(int i=0; i<g->n; i++){
        printf("%c ", name_tag[i]);
        for(int j=0; j<g->n; j++){
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void dfs_mat(GraphType *g, int v){
    visited[v] = 1;
    printf("%c ", name_tag[v]);
    
    for (int w=0; w<g->n; w++){
        if (g->adj_mat[v][w] && !visited[w]){
            dfs_mat(g, w);
        }
    }
}

int main(){
    int point, node;
    GraphType *g;

    g = (GraphType*)malloc(sizeof(GraphType));

    init(g);

    printf("정점의 개수는? ");
    scanf("%d", &point);
    fflush(stdin);
    printf("랜덤 연결 그래프 생성\n");
    printf("간선 수는? ");
    scanf("%d", &node);
    fflush(stdin);

    // i 값이 전체 정점의 개수를 의미함
    for(int i=0; i<point; i++){
        insert_vertex(g, i);
    }

    int cnt = 0;

    srand(time(NULL));

    // 7값이 간선 수를 의미함
    while( cnt != node ){
        int rand_x = rand() % point;
        int rand_y = rand() % point;
        if (rand_x != rand_y){
            cnt += insert_edge(g, rand_x, rand_y);
        }
    }
    print_adj_mat(g);

    printf("DFS: ");
    dfs_mat(g, 0);

    free(g);

    return 0;
}