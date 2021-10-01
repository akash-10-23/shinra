#include<stdio.h>
#include<stdlib.h>
int min(int num1, int num2)
{ return (num1 < num2 ) ? num1 : num2;}
//***************************************
int max(int num1, int num2)
{ return (num1 > num2 ) ? num1 : num2;}
//*****************************************
int main()
{
int n;
scanf("%d",&n);
int cost[n+1];
int min_upto[n+1];
int max_profit[n+1];
for(int i=0;i<n+1;i++)
{ scanf("%d",&cost[i]);}
int small=cost[0];
for(int i=0;i<n+1;i++)
{
for(int j=0;j<=i;j++)
{ small=min(small,cost[j]); }
min_upto[i]=small;
}
int large=0;
for(int i=0;i<n+1;i++)
{
   max_profit[i]=cost[i]-min_upto[i];
     large=max(max_profit[i-1],max_profit[i]);
}
     for(int i=0;i<n+1;i++)
     {  printf("%d  %d  %d\n",cost[i],min_upto[i],max_profit[i]);}
printf("\nMax profit by doing at most one transaction is : %d",large);
return 0;
}

