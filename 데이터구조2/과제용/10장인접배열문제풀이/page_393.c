// 파일에 저장된 인접 행렬을 받아와서 함수 구현
// write_graph_mat (GraphType *g, char *name) 그래프 g의 인접 행렬을 이름이 name인 그래프 파일에 저장
// read_graph_mat (GraphType *g, char *name) 이름이 name인 그래프 파일을 읽어서 그래프 g의 인접 행렬에 저장

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
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
    if(((g->n)+1) > MAX_VERTICES){
        fprintf(stderr, "[insert_vertex]그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int start, int end){
    if(start >= g->n || end >= g->n){
        fprintf(stderr, "[insert_edge]그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType *g){
    for(int i=0; i<g->n; i++){
        for(int j=0; j<g->n; j++){
            printf("%d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

//////////////// 추가한 요소 ////////////////////////////////////////////////////////////////////////

// write_graph_mat (GraphType *g, char *name) 그래프 g의 인접 행렬을 이름이 name인 그래프 파일에 저장
void write_graph_mat(GraphType *g, char *name){
    FILE *fp = fopen(name,"w");

    if(fp == NULL){
        fprintf(stderr,"[write_graph_mat] File Open Error");
        exit(1);
    }
    
    fprintf(fp, "%d\n", g->n);

    for(int i=0; i<g->n; i++){
        for(int j=0; j<g->n; j++){
            fprintf(fp, "%d", g->adj_mat[i][j]);
        }

        if(i != g->n-1){
            fprintf(fp, "\n");
        }
    }
    printf("File Save Successed\n");

    fclose(fp);
}

// read_graph_mat (GraphType *g, char *name) 이름이 name인 그래프 파일을 읽어서 그래프 g의 인접 행렬에 저장
void read_graph_mat(GraphType *g, char *name){
    FILE *fp = fopen(name, "r");

    if(fp == NULL){
        fprintf(stderr, "[read_graph_mat] File Open Error");
        exit(1);
    }

    int n;
    char buffer[100];

    fgets(buffer, sizeof(buffer), fp);
    n = atoi(buffer);

    for(int i=0; i<n; i++){
        insert_vertex(g, i);
    }

    for(int i=0; i<n; i++){
        fgets(buffer, sizeof(buffer), fp);
        for(int j=0; j<n; j++){
            if(buffer[j]=='1'){
                insert_edge(g, i, j);
            }
        }
    }

    printf("Mat Save Successed\n");

    fclose(fp);
}

int main(void){
    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    init(g);    

    read_graph_mat(g, "input.txt");
    write_graph_mat(g, "output.txt");

    print_adj_mat(g);

    free(g);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////