#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"
#define ROWS 10
#define COLS 10

int mat[ROWS][COLS];

void enterValuesForMatrix(){
    printf("Enter values for the 10x10 matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter value for mat[%d][%d]: ", i, j);
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
        for (int i = 0; i < COLS; i++) {
            for (int j = 0; j < ROWS; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist[s][d]!=0;
}

void printPath(int path[ROWS][COLS], int i, int j) {
    if (path[i][j] == -1) {
        printf("%d ", -1);
        return;
    }
    printPath(path, i, path[i][j]);
    printf("%d ", j);
}

void PrintShortestPath(int s,int d) {
    int dist[ROWS][COLS];
    int path[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            dist[i][j] = mat[i][j];
            if (i != j && mat[i][j] != 0) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }
    
    for (int k = 0; k < ROWS; k++) {
        for (int i = 0; i < COLS; i++) {
            for (int j = 0; j < ROWS; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    printPath(path,s,d);
}