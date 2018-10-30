#include <stdio.h>
#include <stdlib.h>

int fmax(int a ,int b){
  return a>b?a:b;
}
int main(){
  int x;
  int f[100],c[100],w[100],a[100][100],n,m;
  scanf("%d %d",&n,&m);//n是总钱数，m是总的工作数，x是组数。
  int t;
  scanf("%d",&t);
  x=m/t;
  int p;
  for(int i = 1; i<=m; i++){
    scanf("%d %d",&w[i],&c[i]);
    p = (i-1-(i-1)%x)/x+1;
    a[p][0]++;//每一组的数量
    a[p][a[p][0]]=i;//每组中每一个的总编号
    t = fmax(t,p);
  }
  int r[x];//记录位置
  for(int i=1;i<=t;i++){    //组的循环
      for(int j=n;j>=0;j--){    //金额的遍历
        for(int k =1;k<=a[i][0];k++){//组内的遍历
         if(w[a[i][k]]<=j){
            int temp=fmax(f[j],f[j-w[a[i][k]]]+c[a[i][k]]);
            if(temp==f[j]){
              r[i]=k;
             }else{
                r[i]=k+1;
             }
             f[j]=temp;
          } 
         printf("%d %d %d  %d\n",i,j,k,f[j]);
       }
      }
  
  }
  printf("%d",f[n]);
  for(int i = 1; i<=t;i++){
    printf("\n%d",r[i]);
  }
  return 0;
}
