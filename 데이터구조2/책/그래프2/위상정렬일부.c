#include <stdio.h>

int topo_sort(GraphType *g){
    StackType s;                                        // 스택
    GraphNode *node;                                    // 그래프 노드

    int *in_degree = (int*)malloc(g->n * sizeof(int));  // 말록으로 동적할당 (리스트 형식)

    for(int i=0; i<g->n; i++){          
        in_degree[i] = 0;                               // 0으로 초기화
    }
    for(int i=0; i<g->n; i++){
        node = g->adj_list[i];                                                                                                                                                                                                                                                                                       

        while(node != NULL){
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    init(&s);

    for(int i=0; i<g->n; i++){
        if(in_degree[i] == 0){
            push(&s, i);
        }
    }

    while(!is_empty(&s)){
        int w = pop(&s);
        printf("정점 %d ->", w);
        node = g->adj_list[w];

        while(node != NULL){
            int u = node->vertex;
            in_degree[u]--;
            
            if(in_degree[u] == 0){
                push(&s, u);
            }
            node = node->link;
        }
    }
    free(in_degree);
    printf("\n");
    return (i == g->n);
}