/*************************************************************************
    > File Name: race.c
    > Author: Yunruowu
    > Mail: xuyunyang12345@163.com
    > Created Time: 2018/10/24 23:46:05
 ************************************************************************/

#include<stdio.h>
FILE *fpread;//读
FILE *fpwrite;//写
int n;
int main()
{
	fpread = fopen("1.txt","r");
  if(fpread==NULL){

    return 0;
  }
  //读入赛马的总组数
  fscanf(fpread,"%d",&n);
  int T[n];//田忌
  int W[n];//齐王
  //从1.txt中读入田忌和齐王的马的速度
  for(int i=0;i<n;i++){
    fscanf(fpread,"%d  %d",&T[i],&W[i]); 
  }
  //利用冒泡排序将田忌和齐王的马进行排序
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
        int temp1,temp2;
        if(T[j]>T[j+1]){
          temp1=T[j];
          T[j] = T[j+1];
          T[j+1] = temp1;
        }
        if(W[j]>W[j+1]){
          temp1=W[j];
          W[j] = W[j+1];
          W[j+1] = temp1;
        }
    }
  }
  fpwrite = fopen("2.txt","w");
  int flag = 1;
  int j;
  j = n-1;
  int m =0;
  int grade = 0;//赢局数
  int equal = 0;//平局数
  fprintf(fpwrite,"策略：\n");
  fprintf(fpwrite,"田  王\n");
  int count =0 ;
  for(int i=n-1;(i>=0)&&(j+1>0);i--)
  { 
    //田忌的未参赛的最快的马从齐王的未参赛的马比较，直到找到一个它可以获胜的。
    while((T[i]<=W[j])&&(j>=1)){
        count++;
        //如果田忌的马比不过，就从拿最小速度的马与它比，消耗一个齐王的快马。
        fprintf(fpwrite,"%d %d   ",T[m],W[j]);
        m++;
        //如果此时两马速度相等则为平局
        if(T[m]==W[j]){
          equal++; 
          fprintf(fpwrite,"平\n");
        }else{
          fprintf(fpwrite,"输\n");
        }
        j--;
        count++;
    }
    j--;
    grade++;
    fprintf(fpwrite,"%d %d   赢\n",T[i],W[j+1]);
  }
  fprintf(fpwrite, "赢局数：  %d\n",grade);
  fprintf(fpwrite, "平局数：  %d\n",equal);
  fprintf(fpwrite, "输局数：  %d\n",n-grade-equal);
  fprintf(fpwrite, "得分：    %d\n",2*grade-n+equal);
  fprintf(fpwrite, "时间复杂度： %d\n", count);
	return 0;
}
