#include <stdio.h>
#define VERTICES 7
int adj_matrix[VERTICES][VERTICES];
int visited[VERTICES];
void dfs(int vertex);
void bfs(int vertex);
int main() {
	int i,j;
    for (i=0;i<VERTICES;i++) {
        for (j=0;j<VERTICES;j++)
            adj_matrix[i][j] = 0;
    }
    adj_matrix[0][1] = 1;
    adj_matrix[0][2] = 1;
    adj_matrix[1][0] = 1;
    adj_matrix[1][3] = 1;
	adj_matrix[2][0] = 1;
    adj_matrix[2][3] = 1;
    adj_matrix[3][1] = 1;
    adj_matrix[3][2] = 1;
    adj_matrix[3][4] = 1;
    adj_matrix[3][5] = 1;
    adj_matrix[4][3] = 1;
    adj_matrix[5][3] = 1;
    printf("Depth First Traversal: ");
    dfs(0);
//    for (i = 0; i < 6; i++) {
//        if (!visited[i])
//            dfs(i);
//    }
    printf("\n");
    for (i = 0; i < 6; i++)
        visited[i] = 0;
    printf("Breadth First Traversal: ");
    bfs(1);
//    for (i = 0; i < 6; i++) {
//        if (!visited[i])
//            bfs(i);
//    }
    printf("\n");
    return 0;
}
void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    int i;
    for (i=0;i<VERTICES;i++) {
        if (adj_matrix[vertex][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}
void bfs(int vertex) {
    int queue[VERTICES];
    int front = -1;
    int rear = -1;
    visited[vertex] = 1;
    queue[++rear] = vertex;
    while (front != rear) {
        vertex = queue[++front];
        printf("%d ", vertex);
        int i;
        for (i=0;i<VERTICES;i++) {
            if (adj_matrix[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}
