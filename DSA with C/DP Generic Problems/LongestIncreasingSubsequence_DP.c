#include<stdio.h>
#include<stdlib.h>
int main()
{
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
{ scanf("%d",&a[i]);}
int LIS[n];
LIS[0]=1;
for(int i=1;i<n;i++)
{
LIS[i]=1;
for(int j=0;j<=i-1;j++)
{
    if(a[i]>a[j]&&LIS[i]<LIS[j]+1)
     LIS[i]=LIS[j]+1;
  }
}
int max=LIS[0];
for(int i=0;i<n;i++)
{
  if(LIS[i]>max)
    max=LIS[i];
}
printf("%d",max);
return 0;
}
