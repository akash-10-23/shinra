#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int ways[n+1];
ways[0]=1;
ways[1]=1;
printf("No of ways to get to heaven on staircase of 0 steps is : %d\n",ways[0]);
printf("No of ways to get to heaven on staircase of 1 steps is : %d\n",ways[1]);
for(int i=2;i<n+1;i++)
{
ways[i]=ways[i-1]+ways[i-2];
printf("No of ways to get to heaven on staircase of %d steps is : %d\n",i,ways[i]);
}
return 0;
}
