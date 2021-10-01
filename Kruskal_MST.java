//Author@ Om Kumar thakur

package firstJavaProgram;

import java.util.concurrent.ThreadLocalRandom;
import java.util.*;
import java.io.*;



//0 1 2
//0 3 3
//3 1 5
//0 2 4
//3 2 6
//1 5 7
//1 4 8
//1 2 3
//2 5 9
//5 4 4
//2 4 2
//5 7 1
//5 6 3
//4 7 2
//4 6 5
//7 6 6


public class Kruskal_MST
{ 
 	 
   class Edge implements Comparable<Edge>      //Comparator class
   { 
       int src;
       int dest;
       int weight; 
  
    public int compareTo(Edge compareEdge)        //Method for comparing the edge on the basis of weight
      { 
        int diff=this.weight - compareEdge.weight; 
        return diff;
       } 
    }; 
    
  
      int vertex;      //vertex 
      int E;   	       //edges
 	  Edge edge[];     //list of edges
 	  
 	  
 	 Kruskal_MST(int v, int e)   // Parameterized constructor for creating the graph with the edges and vertex
 	  {  
        vertex = v;  
        E = e;  	      
        edge = new Edge[E]; 
        
        for (int i = 0; i < e; ++i) 
 	    edge[i] = new Edge(); 
        
 	    } 
 	     
 	    
 	    int find(int subsets[], int i)    //Finding the parent of each for the union of 2 edges   
 	    { 
 	    	//Base Case
 	    	if(subsets[i] == i)
 	    	return subsets[i]; 	
 	    	
 	       //Recursive Case 	   
 	    	subsets[i] = find(subsets, subsets[i]); 
 	    	return subsets[i]; 	
 	    } 
 	  
 	     
 	 	  
 	     void KruskalMST()                     //Method for finding the MST  
 	     { 
 	        Edge out[] = new Edge[vertex];  
 	        
 	        int e=0;
 	        int i= 0;	   
 	        
 	       for (i = 0; i < vertex; ++i)  	            
 	        out[i] = new Edge(); 
 	        
 	        Arrays.sort(edge); 
 	  
 	        int  parent[] = new int[vertex];  	
 	        
 	        for (int v = 0; v < vertex; ++v)  //Creating the vertices assuming that initially all are    
 	        parent[v] = v; 
 	  
 	            i = 0;       
 	  
 	       
 	            
 	        while (e < vertex - 1)            // Number of edges to be taken is equal to vertex-1 
 	        { 
 	             	           
 	         Edge next_edge = new Edge(); 
 	         next_edge = edge[i++]; 
 	  
 	         int x = find(parent, next_edge.src);  	    
 	         int y = find(parent, next_edge.dest);   	       
 	            
 	            if (x != y)                //If parent of source and destination are different means 
 	            {                          //they are not forming cycle then include the edges else discard it
 	            	out[e++] = next_edge;  	 
 	            	parent[x]=y; 
 	            }         
 	        } 
 	         	   
 	        int min_cost = 0; 
 	        
 	       System.out.println("\nSource Vertex   "  +"Destination Vertex  "+"(weight of the edge)\n");  
 	        
 	        for (i = 0; i < e; ++i) 
 	        { 
 	         System.out.println("   "+out[i].src + "                    "  + out[i].dest  + "                     " + out[i].weight+" ");  	        
 	         min_cost += out[i].weight; 
 	        } 
 	        
 	        System.out.println("\nMin. Cost of Spanning tree is : " + min_cost); 
 	      } 
 	     
 	    
 	       public static void main(String[] args)    //Main Method
 	        { 
 	    	  Scanner sc = new Scanner(System.in);
 		      Random rnd = new Random();
 		        
 	          int vertex,edges; 
 	        
              System.out.println("Enter the number of vertex and edges :-"); 
 	        
 	          vertex=sc.nextInt();  	   
 	          edges=sc.nextInt(); 
 	        
 	          Kruskal_MST graph = new Kruskal_MST(vertex,edges); 
 	         
 	        System.out.println("Enter the source, destination vertex and the weight of the edge connecting them:-\n"); 
 	         
 	        for(int i=0;i<edges;i++) 
 	        {  	        
 	        graph.edge[i].src = sc.nextInt();  	 
 	        graph.edge[i].dest = sc.nextInt();  	
 	        graph.edge[i].weight = sc.nextInt(); 
 	        } 
 	        
 	        long start = System.nanoTime(); 
 	        graph.KruskalMST();  	
 	        double end = System.nanoTime();  
 	        
 	        double micro_sec = (end - start) / 1000;  	 	
 	        System.out.println("\nTime for MST using Kruskal's algorithm in micro_sec. is : "+micro_sec);   
 	        
 	    } 
     } 