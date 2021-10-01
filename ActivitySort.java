/*
 *  Activity Sort
 */
import static java.lang.System.*;
import java.util.Random;

public class ActivitySort
{
    static void mcomb(int arr[][],int s,int e)
    {
        int m = (s+e)/2;
        int t1[][] = new int[m-s+1][2],t2[][] = new int[e-m][2];
        int c1=s,c2=m+1;
        for(;c1<=m;c1++)
        {
            t1[c1-s][0] = arr[c1][0];
            t1[c1-s][1] = arr[c1][1];
        }
        for(;c2<=e;c2++)
        {
            t2[c2-m-1][0] = arr[c2][0];
            t2[c2-m-1][1] = arr[c2][1];
        }
        c1=s; 
        c2 =m+1;
        while(c1<=m&&c2<=e)
        {
            if(t1[c1-s][1]<=t2[c2-m-1][1])
            {
                arr[c1+c2-m-1][0] = t1[c1-s][0];
                arr[c1+c2-m-1][1] = t1[c1-s][1];
                c1++;
            }
            else
            {
                arr[c1+c2-m-1][0] = t2[c2-m-1][0];
                arr[c1+c2-m-1][1] = t2[c2-m-1][1];
                c2++;
            }
        }
        for(;c1<=m;c1++)
        {
            arr[c1+c2-m-1][0] = t1[c1-s][0];
            arr[c1+c2-m-1][1] = t1[c1-s][1];
        }
        for(;c2<=e;c2++)
        {
            arr[c2][0] = t2[c2-m-1][0];
            arr[c2][1] = t2[c2-m-1][1];
        }
    }

    static void msort(int arr[][], int s,int e)
    {
        if(s<e)
        {
            int m = (s+e)/2;
            msort(arr,s,m);
            msort(arr,m+1,e);
            mcomb(arr,s,e);
        }
    }

    public static void main(String [] args)
    {
        out.print('\f');
        Random r = new Random();
        int n = 50;         //no. of activities
        int a[][] = new int[n][2];
        for(int t=0;t<n;t++)
        {
            a[t][0] = r.nextInt(95);
            a[t][1] = a[t][0] + r.nextInt(4) + 1;
        }
        /*for(int t=0;t<arr.length-1;t++)
         * out.print(arr[t][1] + " ");
         * out.println();
         */
        msort(a,0,a.length - 1);        //Use of Merge Sort
        out.println("The required activities are");
        out.print("1 ");
        int e= a[0][1];
        for(int t=1;t<n;t++)
            if(a[t][0]>e)
            {
                e=a[t][1];
                out.print((t+1)+" ");
            }
    }
}
