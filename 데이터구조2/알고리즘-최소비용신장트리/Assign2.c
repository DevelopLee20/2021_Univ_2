#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int get_min_vertex(int n){
    int v;
    for(int i=0; i<n; i++){
        if(!selected[i]){
            v = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(!selected[i] && (distance[i] < distance[v])){
            v = i;
        }
    }
    return (v);
}

void prim(GraphType *g, int s){
    for(int u=0; u<g->n; u++){
        distance[u] = INF;
    }
    distance[s] = 0;

    for(int i=0; i<g->n; i++){
        int u = get_min_vertex(g->n);
        selected[u] = TRUE;
        
        if(distance[u] == INF){
            return;
        }
        printf("정점 %d 추가\n", u);

        for(int v=0; v<g->n; v++){
            if(g->weight[u][v] != INF){
                if(!selected[v] && g->weight[u][v] < distance[v]){
                    distance[v] = g->weight[u][v];
                }
            }
        }
    }
}

int main(void){
    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    g->n = 9;

    // 인천:0, 서울:1, 원주:2, 강릉:3, 전주:4, 대전:5, 대구:6, 부산:7, 광주:8
    int list[9][9] = {
        {0,35,INF,INF,245,INF,INF,INF,INF},
        {35,0,123,INF,INF,154,INF,INF,INF},
        {INF,123,0,117,INF,165,222,INF,INF},
        {INF,INF,117,0,INF,INF,INF,INF,INF},
        {245,INF,INF,INF,0,87,INF,INF,98},
        {INF,154,165,INF,87,0,155,INF,122},
        {INF,INF,222,INF,INF,155,0,164,INF},
        {INF,INF,INF,INF,INF,INF,164,0,INF},
        {INF,INF,INF,INF,98,122,INF,INF,0}
    };

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            g->weight[i][j] = list[i][j];
        }
    }

    printf("Prim MST\n");
    // 인천:0, 서울:1, 원주:2, 강릉:3, 전주:4, 대전:5, 대구:6, 부산:7, 광주:8
    prim(g, 1);
    free(g);

    int result = 0;
    for(int i=0; i<9; i++){
        result = result + distance[i];
    }
    printf("MST 간선의 가중치의 합: %d", result);

    return 0;
}