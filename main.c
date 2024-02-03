#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"
#define ROWS 10
#define COLS 10
int main(){
    char type;
    int i,j;
    // printf("Select a function:\n"
    //       "1.Enter A to enter your matrix\n"
    //       "2.Enter B to see if there is a path between two nodes\n"
    //       "3.Enter C to print the shortest path between two nodes\n"
    //       "4.Enter D to exit\n");

    scanf("%c",&type);
    while (type!='D')
    {
        switch (type){
        case 'A':
           enterValuesForMatrix();
        break;

        case 'B':
           // printf("Enter the first node:");
            scanf("%d",&i);
         //   printf("Enter the second node:");
            scanf("%d",&j);
           bool b = FindShortestPath(i,j);
           printf("%c",&b);
        break;

        case 'C':
           // printf("Enter the first node:");
            scanf("%d",&i);
           // printf("Enter the second node:");
            scanf("%d",&j);
            PrintShortestPath(i,j);
        break;
         
        case 'D':
            return 0;
        break;
        
        default:
       // printf("input incorrect!!\n");
        break;
        }

        // printf("Select a function:\n"
        // "1.Enter A to enter your matrix\n"
        // "2.Enter B to see if there is a path between two nodes\n"
        // "3.Enter C to print the shortest path between two nodes\n"
        // "4.Enter D to exit\n");

        scanf("%c",&type);
    }
    return 0;
}