/*
 * Assembly Line Scheduling
 */
import java.io.*;
import java.util.Random;

public class AssemblyLine
{
    static int NUM_LINE = 2; 
    static int n = 15; 
     
    static int min(int a, int b)  
    {  
        return a < b ? a : b;  
          
    } 
      
    static void Assembly(int a[][], int t[][], int e[], int x[]) 
    { 
        int f1[]= new int[n];
        int f2[] =new int[n];
        int I1[]= new int[n];
        int I2[] =new int[n];
        
        int i;
        int I0 = 0;
        f1[0] = e[0] + a[0][0];
        f2[0] = e[1] + a[1][0];
        for (i = 1; i < n; i++)
        {
            f1[i] = min(f1[i - 1] + a[0][i],f2[i - 1] + t[1][i-1] + a[0][i]);
            if(f1[i]==f1[i-1]+a[0][i])
                I1[i]=1;
            else
                I1[i]=2;

            f2[i] = min(f2[i - 1] + a[1][i],f1[i - 1] + t[0][i-1] + a[1][i]);
            if(f2[i]==f2[i-1]+a[1][i])
                I2[i]=2;
            else
                I2[i]=1;
        }
        int fc=min(f1[n-1] + x[0],f2[n-1] + x[1]);
        if(fc==f1[n-1]+x[0])
            I0=1;
        else if(fc==f2[n-1]+x[1])
            I0=2;
        System.out.println("The final cost of assembly is " +fc);
        
        int j=I0;
        System.out.println("The line of assembly is " +j+ " at station " +n);
        for(i=n-1;i>0;i--)
        {
            j=I1[i];
            System.out.println("The line of assembly is " +j+" at station "+i);
        }
    }
    
    public static void main (String[] args)  
    { 
        System.out.println('\f');
        Random r= new Random();
        int a[][] = new int[2][15];  //for stations cost
        int t[][] = new int[2][15];  //for transfer cost
        int e[] = new int[2];
        int x[] = new int[2];        //e=entry cost,x=exit cost
        
        int upper=15, lower=5;
        for(int i=0; i<2;i++)    
            for(int j=0;j<15; j++)
                a[i][j]= r.nextInt((upper-lower)+1) + lower;
        
        t[0][0]=0;
        t[1][0]=0;
        
        for(int i=0; i<2;i++)    
            for(int j=0;j<15; j++)
            {
                if((i!=0 && j!=0) || (i!=1 && j!=0))
                    t[i][j]= r.nextInt((upper-lower)+1) + lower;
            }
        
        for(int i=0; i<2;i++) 
        {
            e[i]= r.nextInt((upper-lower)+1) + lower;
            x[i]= r.nextInt((upper-lower)+1) + lower;
        }
        
        Assembly(a, t, e, x);     
    } 
}
