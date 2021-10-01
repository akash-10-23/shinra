#include<stdio.h>
#include<stdlib.h>
int max(int num1, int num2)
{ return (num1 > num2 ) ? num1 : num2;}
//*****************************************
int main()
{
 int n;
scanf("%d",&n);
int max_product[n+1];
max_product[0]=0;
max_product[1]=0;
max_product[2]=1;
printf("Max product by splitting 0 int two or more integers is : %d\n",max_product[0]);
printf("Max product by splitting 1 int two or more integers is : %d\n",max_product[1]);
printf("Max product by splitting 2 int two or more integers is : %d\n",max_product[2]);
for(int i=3;i<n+1;i++)
{
 max_product[i]=0;
 for(int j=1;j<=i-1;j++)
{ max_product[i]=max(max_product[i],max(j*max_product[i-j],j*(i-j))); }
printf("Max product by splitting %d int two or more integers is : %d\n",i,max_product[i]);
}
return 0;
}

