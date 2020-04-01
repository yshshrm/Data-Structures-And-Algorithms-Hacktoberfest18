import java.io.*;
import java.util.*;
class prim
{
    int visited[]=new int[10],min;
    void initial(int cost[][],int n)
    {
        int i,j,count=1,u,v,a,b,mincost=0;
        a=b=u=v=i=j=min=0;
        for(i=0;i<n;i++)
        {
            visited[i]=0;
        }
        visited[0]=1;
        while(count<n)
        {
            for(i=0,min=999;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(cost[i][j]<min&&visited[i]!=0)
                    {
                        min=cost[i][j];
                        u=a=i;
                        v=b=j;
                    }
                }
            }
            if(visited[u]==0||visited[v]==0)
            {
                count++;
                System.out.println(count+" "+"("+u+","+v+")");
                mincost+=min;
                visited[b]=1;
            }cost[a][b]=cost[b][a]=999;
        }System.out.println(mincost);
    }
    public static void main(String ar[])
    {
        prim p=new prim();
        int n,i,j;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter no of nodes ");
        n=sc.nextInt();
        int a[][]=new int[10][10];
        System.out.println("Enter adjacency matrix ");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {  
                a[i][j]=sc.nextInt();       
            }
        }
        p.initial(a,n);
    }
}           
