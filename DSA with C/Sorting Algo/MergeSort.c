#include<stdio.h>
//Function for merging the 2 sub arrays and storing it in the new array named b[].
void merge(int a[],int n1,int idx1,int b[],int n2,int idx2,int c[],int idx)
{
     while(n1&&n2)//if both the sub arrays has at least 1 element
    {
        if(a[idx1]<b[idx2])
        {
            c[idx]=a[idx1];
            idx++;
            idx1++;
            n1--;
        }
        else
    {
            c[idx]=b[idx2];
            idx++;
            idx2++;
            n2--;
        }
    }//end of while
    while(n1)//if second sub array has 0 element
    {
      c[idx]=a[idx1];
            idx++;
            idx1++;
            n1--;
    }
        while(n2)//if first sub array has 0 element
    {
            c[idx]=b[idx2];
            idx++;
            idx2++;
            n2--;
        }
    }
    //Function for passing the sub arrays to be merged
void mergepass(int a[],int n,int L,int b[])
{
    int q,s,r;
    q=n/(2*L);       //q = total no of array pairs to be merged
    s=2*L*q;        //s= total no of elements int the array pair
    r=n-s;         //r = total no of elements which has not been paired
 for(int i=0;i<q;i++)
 {
  int Lb=(2*i)*L;  //lower bound index of the first sub array
    merge(a,L,Lb,a,L,Lb+L,b,Lb);  //merging the two sub arrays
 }
 if(r<=L)//if only one sub array left
 {
  for(int i=0;i<r;i++)
 { b[s+i]=a[s+i]; }
}
  else //if the last pair of arrays are of unequal size
{ merge(a,L,s,a,r-L,s+L,b,s); }
  }
  //Function for sorting the whole array
  void merge_sort(int a[],int n)
  {
      int L=1;//Length of sub array to be merged
      int b[n];//array in which merged sub arrays will be stored
      while(L<n)
      {
        mergepass(a,n,L,b);
        mergepass(b,n,2*L,a);
        L=4*L;
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
         merge_sort(a,n);
            printf("The sorted elements are :-\n");
          for(int i=0;i<n;i++)
      { printf("%d ",a[i]); }
      return 0;
  }
