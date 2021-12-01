#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[]){
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;

    for(i=0; i<n; i++){
        if(distance[i] < min && !found[i]){
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void print_status(GraphType *g){
    static int step = 1;
    for(int i=0; i<g->n; i++){
        if(distance[i] == INF){
            printf("INF "); // 수정된 부분
        }
        else{
            printf("%3d ", distance[i]);
        }
    }
    printf("\n");
}

void short_path(GraphType *g, int start){
    int i, u, w;
    for(i=0; i<g->n; i++){
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }
    found[start] = TRUE;
    printf(" {%d}\n", start+1); // 수정된 부분
    distance[start] = 0;
    for(i=0; i<g->n-1; i++){
        print_status(g);
        u = choose(distance, g->n, found);
        printf(" {%d}\n", u+1); // 수정된 부분
        found[u] = TRUE;
        for(w=0; w<g->n; w++){
            if(!found[w]){
                if(distance[u] + g->weight[u][w] < distance[w]){
                    distance[w] = distance[u] + g->weight[u][w];
                }
            }
        }
    }
}

int main(void){
    GraphType g = {6,{
        {0,10,INF,30,100,INF},
        {INF,0,50,INF,INF,INF},
        {INF,INF,0,INF,10,5},
        {INF,INF,20,0,INF,15},
        {INF,INF,INF,60,0,INF},
        {INF,INF,INF,INF,INF,0},
    }};

    short_path(&g, 0);

    int sum = 0;
    for(int i=0; i<g.n; i++){
        sum += distance[i];
    }
    printf("\nShortest Path: %d", sum);
    return 0;
}