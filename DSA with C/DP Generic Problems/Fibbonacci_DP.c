#include<stdio.h>//very fast to print 10 terms it takes 0.762 seconds and there is flaw with data type if we print till 1000 terms because it long long int cant handle those terms....
int main()
{
int n;
scanf("%d",&n);
long long int f[n];
f[0]=1;
f[1]=1;
for(long long int i=2;i<n;i++)
{
f[i]=f[i-1]+f[i-2];
}
for(long long int i=0;i<n;i++)
{
printf("%lld\n",f[i]);
}
return 0;
}
