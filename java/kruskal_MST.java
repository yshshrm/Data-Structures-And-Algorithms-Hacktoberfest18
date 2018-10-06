
import java.util.Arrays;
import java.util.Comparator;

class Kruskal_MST
{
    int nodes, parent[];
    Edge[] edges;
    
    static final Comparator<Edge> com = new Comparator<Edge>()
    {
        @Override
        public int compare(Edge a, Edge b)
        {
            return Long.compare(a.val, b.val);
        }
    };
    
    Kruskal_MST(int n, Edge[] all)
    {
        nodes = n;  edges = all;
        Arrays.sort(edges, com);
    }
    
    Edge[] MST()
    {
        Edge[] ret = new Edge[nodes -1];
        parent = new int[nodes];
        int i, a, b, ra, rb, end = 0;
        
        for(i = 0; i < nodes; ++i)
            parent[i] = i;
        for(i = 0; i < edges.length; ++i)
        {
            a = edges[i].u;     b = edges[i].v;
            ra = findRoot(a);   rb = findRoot(b);
            if(ra == rb)
            {
                assignUp(a, ra);
                assignUp(b, rb);
                continue;
            }
            ret[end++] = edges[i];
            if(ra < rb)
                assignUp(b, ra);
            else
                assignUp(a, rb);
        }
        return ret;
    }
    int findRoot(int node)
    {
        while(node != parent[node])
            node = parent[node];
        return node;
    }
    void assignUp(int node, int root)
    {
        int temp;
        while(parent[node] != root)
        {
            temp = parent[node];
            parent[node] = root;
            node = temp;
        }
    }
}


class Edge
{
    int u,v;long val;
    Edge(int a,int b,long wt)
    {
        u=a;    v=b;    val=wt;
    }
    int getOtherVertex(int p)
    {
        return u==p? v: v==p? u: -1;
    }
    String getString()
    {
        return "(" + u + ", " + v + " --> " + val + ")";
    }
}
