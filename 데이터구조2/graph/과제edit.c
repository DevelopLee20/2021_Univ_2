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
} GraphType;

typedef struct ListNode{
    int data;
    struct ListNode *link;
} ListNode;

void get_node(ListNode *l, int item){

    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

    node = l;

    while( node != NULL ){
        node = node->link;
    }
    node->data = item;
    l->link = node;
}

void init(GraphType *g){
    g->n = 0;
    for (int r=0; r<MAX_VERTICES; r++){
        for (int c=0; c<MAX_VERTICES; c++){
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType *g, int v){
    if (((g->n)+1) > MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

int insert_edge(GraphType *g, int start, int end){
    if (start >= g->n || end >= g->n){
        fprintf(stderr, "그래프: 정점의 번호 오류");
        exit(1);
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType* g){
    for(int i=0; i<g->n; i++){
        printf("%c ", i+65);
        for(int j=0; j<g->n; j++){
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void print_adj_list(ListNode* l, int point){
    ListNode *node = l;

    printf("%c -> ", point+65);
    while( node != NULL ){
        printf("%d ", node->data);
        node = node->link;
    }
}

void dfs_mat(GraphType *g, int v){
    visited[v] = 1;
    printf("%c ", v+65);
    
    for (int w=0; w<g->n; w++){
        if (g->adj_mat[v][w] && !visited[w]){
            dfs_mat(g, w);
        }
    }
}

// 1. 무작위로 그래프를 발생시키는 함수
void rand_vertex(GraphType *g, int node, int point){
    srand(time(NULL));
    int cnt = 0;

    while( cnt != node ){
        int rand_x = rand() % point;
        int rand_y = rand() % point;
        if (rand_x != rand_y && g->adj_mat[rand_x][rand_y] != 1){
            insert_edge(g, rand_x, rand_y);
            cnt++;
        }
    }
}

int main(void){
    int point, node;
    GraphType *g;
    ListNode *l[MAX_VERTICES];

    for(int i=0; i<MAX_VERTICES; i++){
        l[i] = (ListNode*)malloc(sizeof(ListNode));
    }
    g = (GraphType*)malloc(sizeof(GraphType));

    init(g);

    printf("정점의 개수는? ");
    scanf("%d", &point);
    fflush(stdin);
    printf("랜덤 연결 그래프 생성\n");
    printf("간선 수는? ");
    scanf("%d", &node);
    fflush(stdin);

    for(int i=0; i<point; i++){
        insert_vertex(g, i);
    }

    rand_vertex(g, node, point);

    print_adj_mat(g);

    printf("DFS: ");
    dfs_mat(g, 0);

    for(int i=0; i<g->n; i++){
        for(int j=g->n; j>i; j--){
            if( g->adj_mat[i][j] == 1 ){
                get_node(l[i], j);
            }
        }
        printf("\n");
    }

    for(int i=0; i<point; i++){
        print_adj_list(l[i], point);
    }

    free(g);

    return 0;
}