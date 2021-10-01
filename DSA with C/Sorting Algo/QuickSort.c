#include<stdio.h>
//function for the procedure of quick sort
void quick(int a[],int n,int beg,int end,int *locptr)
{
int left,right;//initializing beg and end of the sub arrays created due to loc(index of the element to be placed at the correct position)
left=beg;
right=end;
*locptr=beg;
int temp=0;
step2://use of goto because we have to shift from left subpart to right subpart
   while(a[*locptr]<=a[right]&&*locptr!=right)
    right--;
   if(*locptr==right)
    return;
    if(a[*locptr]>a[right])
    {
     temp=a[*locptr];
    a[*locptr]=a[right];
     a[right]=temp;
     *locptr=right;
    }
    goto step3;
step3:
    while(a[left]<=a[*locptr]&&*locptr!=left)
    left++;
   if(*locptr==left)
    return;
    if(a[*locptr]<a[left])
    {
     temp=a[*locptr];
     a[*locptr]=a[left];
     a[left]=temp;
     *locptr=left;
    }
    goto step2;
 }
 //Function to perform the quick sort
 void quick_sort(int a[],int n)
{
   int top=-1;//stack to store the indexes of the left and right sub array
   int beg=0;
   int end=0;
    int loc;
   int lower[10];//for left sub array
   int upper[10];//for right sub array
   if(n>1)//push operation
   {
       top++;
       lower[top]=0;
       upper[top]=n-1;
   }
   while(top!=-1)
   {
    beg=lower[top];
    end=upper[top];
    top--;//pop operation
    quick(a,n,beg,end,&loc);
    if(beg<loc-1)//push operation
    {
     top=top+1;
     lower[top]=beg;
     upper[top]=loc-1;
    }
    if(loc+1<end)//push operation
    {
    top+=1;
    lower[top]=loc+1;
    upper[top]=end;
    }
   }
}
  int main()
  {
      int n;
      printf("Enter the size of the array\n");
      scanf("%d",&n);
      int a[n];
      printf("Enter the elements of the array:-\n");
      for(int i=0;i<n;i++)
      { scanf("%d",&a[i]); }
         quick_sort(a,n);
            printf("The sorted elements are :-\n");
          for(int i=0;i<n;i++)
      { printf("%d ",a[i]); }
      return 0;
  }
