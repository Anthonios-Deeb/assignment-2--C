#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

int main(){
    char type;
    int i,j;

    scanf("%c",&type);
    while (type!='D')
    {
        switch (type){
        case 'A':
           enterValuesForMatrix();
        break;

        case 'B':
            scanf("%d",&i);
            scanf("%d",&j);
            bool b = FindShortestPath(i,j);
            printf("%s\n",b ? "True":"False");
        break;

        case 'C':
            scanf("%d",&i);
            scanf("%d",&j);
            PrintShortestPath(i,j);
        break;
         
        case 'D':
            return 0;
        break;
        
        default:
        break;
        }
        scanf("%c",&type);
    }
    return 0;
}