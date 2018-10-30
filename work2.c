#include<stdio.h>
#include<stdlib.h>

int main(){
    int S,M,N;
    scanf("%d %d %d",&S,&M,&N);
    printf("%d %d %d\n",S,M,N);
    int V[M][N/M],P[M][N/M];
    for(int i = 0; i < M; i++){
      for(int j = 0; j<N/M; j++){
         scanf("%d",&V[i][j]);
      }
    }
    for(int i = 0; i < M; i++){
      for(int j = 0; j<N/M; j++){
         scanf("%d",&P[i][j]);
      }
    }
    int C = N/M;
    printf("%d\n",C);
    int F[M][S];
    for(int i = 0;i<M;i++){
      for(int j = 0;j<C;j++){
        F[i][j]=0;
      }
    }
    for(int i = 1; i < M; i++){
      for(int j = S-1; j > 0; j--){
        for(int k = 0;k < C; k++){
          int temp;
          if((j-P[i][k])>=0)
            temp = F[i][j-P[i][k]]+V[i][k];
          else {
            temp = 0;
          }
          if(temp>F[i-1][j])
            F[i][j]=temp;
          else
            F[i][j]=F[i-1][j];
        }
      }
    }
    printf("%d\n",F[M-1][S-1]);

    return 0;
}
