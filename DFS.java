/*
 *  Depth First Search
 */
import java.io.*; 
import java.util.*; 

class DFS
{ 
	private int V; 
	private LinkedList<Integer> adj[]; 

	DFS(int v) 
	{ 
		V = v; 
		adj = new LinkedList[v]; 
		for (int i=0; i<v; ++i) 
			adj[i] = new LinkedList(); 
	} 

	void addEdge(int v, int w) 
	{ 
		adj[v].add(w);  
	} 

	void DFSUtil(int v,boolean visited[]) 
	{ 
		visited[v] = true; 
		System.out.print(v+" "); 
 
		Iterator<Integer> i = adj[v].listIterator(); 
		while (i.hasNext()) 
		{ 
			int n = i.next(); 
			if (!visited[n]) 
				DFSUtil(n, visited); 
		} 
	} 
	
	void traverse(int v) 
	{ 
		boolean visited[] = new boolean[V]; 
		DFSUtil(v, visited); 
	} 

	public static void main(String args[]) 
	{ 
		System.out.print('\f');
	        Scanner s= new Scanner(System.in);
	        int v,n,x,y;
	        System.out.print("Enter no. of vertices: ");
	        v=s.nextInt();
	        System.out.print("Enter no. of edges: ");
	        n= s.nextInt();
		DFS g = new DFS(v); 
		
		System.out.println("Enter Edges: ");
		for(int i=0; i<n; i++)
		{
		    System.out.print("Enter x: ");
		    x=s.nextInt();
		    System.out.print("Enter y: ");
		    y=s.nextInt();
		    System.out.println();
		    g.addEdge(x,y);
		}
		System.out.print("Enter starting point: ");
		int st=s.nextInt();
		System.out.println("Following is Depth First Traversal (starting from vertex "+st+" )"); 
		g.traverse(st); 
	} 
} 

