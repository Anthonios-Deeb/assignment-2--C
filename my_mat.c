#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"
#define N 10
int mat[N][N];

void enterValuesForMatrix(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

bool FindShortestPath(int s,int d){
    if(s==d)
        return false;

    int dist[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = mat[i][j];
        }
    }
    for (int k = 0; k < N; k++) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (dist[x][k] != 0 && dist[k][y] != 0 && (dist[x][y] == 0 || dist[x][k] + dist[k][y] < dist[x][y])) {
                    dist[x][y] = dist[x][k] + dist[k][y];
                }
            }
        }
    }

    return dist[s][d]!=0;
}

void PrintShortestPath(int s,int d) {
    if(s==d){
        printf("%d\n",-1);
        return;
    }
   int dist[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = mat[i][j];
        }
    }

    for (int k = 0; k < N; k++) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (dist[x][k] != 0 && dist[k][y] != 0 && (dist[x][y] == 0 || dist[x][k] + dist[k][y] < dist[x][y])) {
                    dist[x][y] = dist[x][k] + dist[k][y];
                }
            }
        }
    }
    if(dist[s][d]==0){
        printf("%d\n",-1);
    }else{
        printf("%d\n",dist[s][d]);
    }
}
