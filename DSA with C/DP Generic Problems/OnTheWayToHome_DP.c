#include<stdio.h>
int main()
{
int m,n;
scanf("%d",&m);
scanf("%d",&n);
int num_ways[m][n];

for(int i=0;i<=m-1;i++)
  {num_ways[i][n-1]=1;}

for(int j=0;j<=n-1;j++)
  {num_ways[m-1][j]=1;}

  for(int i=m-2;i>=0;i--)
  {
   for(int j=n-2;j>=0;j--)
   {  num_ways[i][j]= num_ways[i][j+1]+ num_ways[i+1][j]; }
 }
 printf("No of ways to reach the bottom right of %d * %d square from top left corner is : %d",m,n,num_ways[0][0]);
 return 0;
}

