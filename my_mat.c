#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"
#define ROWS 10
#define COLS 10

int mat[ROWS][COLS];

void enterValuesForMatrix(){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

bool FindShortestPath(int s,int d){
    int dist[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            dist[i][j] = mat[i][j];
        }
    }
    for (int k = 0; k < ROWS; k++) {
        for (int x = 0; x < COLS; x++) {
            for (int y = 0; y < ROWS; y++) {
                if (dist[x][k] != 0 && dist[k][y] != 0 && (dist[x][y] == 0 || dist[x][k] + dist[k][y] < dist[x][y])) {
                    dist[x][y] = dist[x][k] + dist[k][y];
                }
            }
        }
    }

    return dist[s][d]!=0;
}

void PrintShortestPath(int s,int d) {
   int dist[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            dist[i][j] = mat[i][j];
        }
    }
    for (int k = 0; k < ROWS; k++) {
        for (int x = 0; x < COLS; x++) {
            for (int y = 0; y < ROWS; y++) {
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