import java.util.Arrays;

public class FloydWarshall {
	/* O algoritmo só funciona quando o grafo é convertido em matriz */
	
    private double[][] graph;
    private boolean negativeCycle;

    public FloydWarshall(int n) {
        this.graph = new double[n][n];
        initGraph();
    }
    
    /* inicialização do grafo */
    private void initGraph() {
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph.length; j++) {
                if (i == j) {
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = Double.POSITIVE_INFINITY;
                }
            }
        }
    }

    public boolean hasNegativeCycle() {
        return this.negativeCycle;
    }

    public void addEdge(int from, int to, double weight) {
        graph[from][to] = weight;
    }

    public double[][] floydWarshall() {
        double[][] distances;
        int n = this.graph.length;
        distances = Arrays.copyOf(this.graph, n);

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    distances[i][j] = Math.min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
            if (distances[k][k] < 0.0) {
                this.negativeCycle = true;
            }
        }
        return distances;
    }

}
