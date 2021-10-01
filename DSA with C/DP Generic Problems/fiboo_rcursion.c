#include<stdio.h>
int fib(int );
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
   { printf("%d ",fib(i)); }
    return 0;
}
int fib(int n)
{
  if(n==1||n==2)
    return(1);
  if(n>2)
   return(fib(n-1)+fib(n-2));
  }
