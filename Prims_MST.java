//Author@ Om Kumar thakur

package firstJavaProgram;

import java.util.concurrent.ThreadLocalRandom;
import java.util.*;
import java.io.*;


public class Prims_MST
{ 
	 
  int minValue(int key[], Boolean mstSet[],int v) 
	  { 
	        
	    int min = Integer.MAX_VALUE, min_index = -1;   // Initialize min value 
	  
	    for (int i = 0; i <v ; i++) 
	     if (mstSet[i] == false && key[i] < min) 
	        {  	          
	            	min = key[i];  	    
	            	min_index = i; 
	        } 
	        return min_index; 
	    } 
	  
	  
	 
	 void printMST(int parent[], int graph[][]) 
	    {  
		 int min_weight=0; 
		 
		 System.out.println("\nSource Vertex   "  +"Destination Vertex  "+"(weight of the edge)\n");  
		 
	        for (int i = 1; i < parent.length; i++) 
	        { 
	         System.out.println("   "+parent[i] + "                    "  + i  + "                     " + graph[i][parent[i]]+" \n");
	         min_weight+= graph[i][parent[i]];    
	        } 
	        
	        System.out.println("Total weight of minimum spanning tree is : "+min_weight+"\n"); 
	    } 
	 
	 
	void prims_method(int graph[][],int n) 
	{  	 	                                       
		int parent[] = new int[n];     
		int key[] = new int[n]; 

      Boolean mstSet[] = new Boolean[n]; 
      
      for (int i = 0; i < n; i++)
      {            
    	  key[i] = Integer.MAX_VALUE;       
    	  mstSet[i] = false; 
      } 
 
      key[0] = 0; 
     
      parent[0] = -1; 

     
      for (int count = 0; count < n - 1; count++) 
      {           
    	  int u = minValue(key, mstSet,n); 
        
    	  mstSet[u] = true; 
    	  
    	  for (int v = 0; v < n; v++)   
    	  {
             if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v])
             {            
              parent[v] = u;             
              key[v] = graph[u][v]; 
              } 
    	  }
      }
        printMST(parent, graph); 
  } 
	 
	 
	public static void main(String[] args)
	{ 
		
		 Scanner sc = new Scanner(System.in); 
		
	    Prims_MST p=new Prims_MST(); 
	    
	    System.out.println("Enter the number of vertices :-");
	    
	   
	    
	    int vertices = sc.nextInt(); 
	    int x; 
	    int graph[][] = new int[vertices][vertices]; 
	    
	    for(int i=0;i<vertices;i++) 
	     { 
	     for(int j=0;j<vertices;j++) 
	     { 
	     System.out.print("Enter the weight of the egde between "+"("+ i +"," +j+") : ");                
	     x = sc.nextInt();     
         graph[i][j] = x; 
	     }
	    } 
	   
     
          long start = System.nanoTime(); 
          p.prims_method(graph,vertices); 
          long end = System.nanoTime();  	
          
          long microseconds = (end - start) / 1000;  	 	 
          System.out.println("Time for MST using Prim's algo in micro seconds is "+microseconds); 

	} 
} 
