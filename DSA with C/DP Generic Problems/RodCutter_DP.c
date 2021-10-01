#include<stdio.h>
#include<stdlib.h>
int max(int num1, int num2)
{ return (num1 > num2 ) ? num1 : num2;}
//*****************************************
int main()
{
int n;
scanf("%d",&n);
int cost[n+1];
int rod[n+1];
for(int i=0;i<n+1;i++)
{ scanf("%d",&cost[i]);}
rod[0]=cost[0];
printf("Max revenue that can be earned by selling the 0 pieces is : %d\n",rod[0]);
for(int i=1;i<n+1;i++)
{
int maxim=0;
for(int j=1;j<=i;j++)
{ maxim=max(maxim,cost[j]+rod[i-j]); }
rod[i]=maxim;
printf("Max revenue that can be earned by selling the %d pieces is : %d\n",i,rod[i]);
}
return 0;
}

