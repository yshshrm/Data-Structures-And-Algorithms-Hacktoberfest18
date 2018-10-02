package shortestDistance;

import java.util.Scanner;

public class Dijkstra {

	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int e=s.nextInt();
		
		int edges[][]=new int[n][n];
			
		for(int i=0;i<e;i++)
		{
			int fv=s.nextInt();
			int sv=s.nextInt();
			int wt=s.nextInt();
			edges[fv][sv]=wt; 
			edges[sv][fv]=wt;  //undirected graph
		}

		Dijkstraa(edges);
	}

	public static void Dijkstraa(int[][] edges) {
		boolean visited[]=new boolean[edges.length];
		int distance[]=new int[edges.length];
		
		for(int i=0;i<distance.length;i++)
		{
			distance[i]=Integer.MAX_VALUE;
			visited[i]=false;
		}
		distance[0]=0;
		
		for(int i=0;i<edges.length;i++)
		{
			int currentV=findMinDistVertex(visited,distance);
			visited[currentV]=true;
			for(int j=0;j<edges.length;j++)
			{
				if(!visited[j] && edges[currentV][j]!=0)
				{
					if(distance[j]>distance[currentV]+edges[currentV][j])
					{
						distance[j]=distance[currentV]+edges[currentV][j];
					}
				}
			}
		}
		
		for(int i=0;i<distance.length;i++)
		{
			System.out.println(i+" "+distance[i]);
		}
		
	}

	private static int findMinDistVertex(boolean[] visited, int[] distance) {
		int min=Integer.MAX_VALUE;
		int minVertex=0;
		
		for(int i=0;i<distance.length;i++)
		{
			if(!visited[i] && distance[i]<min)
			{
				min=distance[i];
				minVertex=i;
			}
		}
		
		return minVertex;
	}

}
