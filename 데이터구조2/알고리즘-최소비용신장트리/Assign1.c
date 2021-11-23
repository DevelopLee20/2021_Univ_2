#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

int result = 0;

void set_init(int n){
    for(int i=0; i<n; i++){
        parent[i] = -1;
    }
}

// curr가 속하는 집합을 반환한다
int set_find(int curr){
    if(parent[curr] == -1){
        return curr;
    }
    while(parent[curr] != -1){
        curr = parent[curr];
    }
    return curr;
}

// 두개의 원소가 속한 집합을 합친다
void set_union(int a, int b){
    int root1 = set_find(a);
    int root2 = set_find(b);

    if(root1 != root2){
        parent[root1] = root2;
    }
}

struct Edge{
    int start, end, weight;
};

typedef struct GraphType{
    int n;
    struct Edge edges[2*MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g){
    g->n = 0;

    for(int i=0; i<2*MAX_VERTICES; i++){
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

void insert_edge(GraphType *g, int start, int end, int w){
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

int compare(const void *a, const void *b){
    struct Edge *x = (struct Edge*)a;
    struct Edge *y = (struct Edge*)b;

    return (x->weight - y->weight);
}

void kruskal(GraphType *g){
    int uset, vset;
    struct Edge e;

    set_init(g->n);
    qsort(g->edges, g->n, sizeof(struct Edge), compare);

    printf("크루스칼 최소 신장 트리 알고리즘 \n");

    for(int i=0; i<g->n; i++){
        e = g->edges[i];
        uset = set_find(e.start);
        vset = set_find(e.end);

        if(uset != vset){
            printf("간선 (%d,%d) %d 선택\n", e.start, e.end, e.weight);
            result = result + e.weight; // 이거
            set_union(uset, vset);
        }
    }
}

int main(void){
    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);

    // 인천:0, 서울:1, 원주:2, 강릉:3, 전주:4, 대전:5, 대구:6, 부산:7, 광주:8
    int list[9][9] = {
        {0,35,INF,INF,245,INF,INF,INF,INF},
        {35,INF,123,INF,INF,154,INF,INF,INF},
        {0,123,INF,117,INF,165,222,INF,INF},
        {0,INF,117,INF,INF,INF,INF,INF,INF},
        {245,INF,INF,INF,INF,87,INF,INF,98},
        {0,154,165,INF,87,INF,155,INF,122},
        {0,INF,222,INF,INF,155,INF,164,INF},
        {0,INF,INF,INF,INF,INF,164,INF,INF},
        {0,INF,INF,INF,98,122,INF,INF,INF},
    };

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(list[i][j] != 0)
                insert_edge(g,i,j,list[i][j]);
        }
    }
    kruskal(g);
    free(g);

    printf("MST 간선의 가중치의 합: %d", result);

    return EXIT_SUCCESS;
}