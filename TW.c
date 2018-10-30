#include<stdio.h>
FILE *fpread;//读取文件
FILE *fpwrite;//写入文件
int n;//马的组数
int f[100][100];
int grade = 0; 
int max(int a,int b){
  return a>b?a:b;
}
int main()
{
	fpread = fopen("1.txt","r");//打开输入的文件
  if(fpread==NULL){

    return 0;
  }
  fscanf(fpread,"%d",&n);
  int T[n+1];
  int W[n+1];
  for(int i=1;i<=n;i++){
    fscanf(fpread,"%d  %d",&T[i],&W[i]); 
  }

  //排序
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i;j++){
        int temp1,temp2;
        if(T[j]<T[j+1]){
          temp1=T[j];
          T[j] = T[j+1];
          T[j+1] = temp1;
        }
        if(W[j]<W[j+1]){
          temp1=W[j];
          W[j] = W[j+1];
          W[j+1] = temp1;
        }
    }
  }
  int c[100][100];
  for(int i =1 ;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(T[i]>W[j])
        c[i][j]=1;
      else if(T[i]==W[j])
            c[i][j]=0;
      else 
        c[i][j] =-1;
    }
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      f[i][j]=-1;
  }
  int a[n+1];
  f[0][0]=0;
  //计算出动态规划的解
  int count=0;
  for(int i = 1;i<=n;i++){  //国王的第i匹马
    for(int j=0;j<=i;j++){
      if(j>=1){
        f[i][j]=max(f[i-1][j]+c[n-(i-j)+1][i],f[i-1][j-1]+c[j][i]);
        if(f[i][j]==(f[i-1][j]+c[n-(i-j)+1][i]))
        {
          a[i]=j;
        }else{
          a[i]=j-1;
        }
        count++;
      }
      else 
        f[i][j]=f[i-1][j]+c[n-(i-j)+1][i];
      printf("%2d   "   ,f[i][j]);
    }
    printf("\n");
  }
  for(int i=0;i<=n;i++){
    grade = max(f[n][i],grade);
    printf("%d     ",f[n][i]);
  }
  printf("%d",grade);
  
  fpwrite = fopen("3.txt","w");
  fprintf(fpwrite,"比分：%d\n",grade);
  fprintf(fpwrite,"时间复杂度：%d",count);
  fclose(fpread);
  fclose(fpwrite);
  return 0;
}
