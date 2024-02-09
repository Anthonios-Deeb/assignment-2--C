#include <stdio.h>
#define N 5
#define C 20
int knapSack(int[],int[],int[]);

int main(){
    char items[N];
    int values[N];
    int weights[N];
    int selected_bool[N]={0};
    char result[N];

    for(int i=0;i<N;i++){
        scanf("%s",&items[i]);
        scanf("%d",&values[i]);
        scanf("%d",&weights[i]);
    }

    
   int sum =knapSack(weights,values,selected_bool);

    int k=0;
    for(int i=0;i<N;i++){
        if(selected_bool[i]==1){
            result[k]=items[i];
            k++;
        }
    }

    printf("Maximum profit: ");
    printf("%d\n",sum);
    printf("Selected items:");
    for (int i = 0; i < k; i++){
        printf(" %c",result[i]);
    }
    
    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int weights[],int values[],int selected_bool[]){
    int dp[N+1][C+1];

    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= C; j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(j>=weights[i-1]){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i-1]]+values[i-1]);
            }else {
                dp[i][j]=dp[i-1][j];
            }   
        }
    }

    int j=C;
    for(int i=N;i>0;i--){
        if (dp[i][j] != dp[i - 1][j]) {
            selected_bool[i - 1] = 1;
            j -= weights[i - 1];
        }
    }
    return dp[N][C];
}