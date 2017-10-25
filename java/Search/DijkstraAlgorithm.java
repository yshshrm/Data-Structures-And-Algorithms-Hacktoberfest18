import java.util.ArrayList;
import java.util.Objects;
import java.util.Stack;
import java.util.StringTokenizer;

public class DijkstraAlgorithm {

    private ArrayList<Vertex> vertices;
    private ArrayList<Edge> edges;
    private String fileGraph;

    public DijkstraAlgorithm(String fileGraph) {
        this.fileGraph = fileGraph;
        vertices = new ArrayList<Vertex>();
        edges = new ArrayList<Edge>();
        generateWeightedGraph();
    }

    /*
     * creates a graph based on the given textfile
     */
    public void generateWeightedGraph() {
        //this is needed because edges cant be created before the sink Verticles are created
        ArrayList<String> edgesToCreate = new ArrayList<String>();
        StringTokenizer st = new StringTokenizer(fileGraph, "\n");

        //prepares the string with the help of the string tokenizer
        while (st.hasMoreTokens()) {
            String currentLine = st.nextToken();
            StringTokenizer st2 = new StringTokenizer(currentLine);
            //src
            String src = st2.nextToken(" ");
            vertices.add(new Vertex(src));
            //other points - here a loop is needed
            while (st2.hasMoreTokens()) {
                String currentSink = st2.nextToken();
                edgesToCreate.add(currentSink + "," + src);
            }
        }
        //create the edges
        for (String s : edgesToCreate) {
            StringTokenizer sts = new StringTokenizer(s, ",");
            String sink = sts.nextToken();
            int weight = Integer.parseInt(sts.nextToken());
            String src = sts.nextToken();
            edges.add(new Edge(getVertex(src), getVertex(sink), weight));
        }
    }

    /*
     * Dijkstra algorithm
     */
    public void dijkstra(String start, String end) {
    	  //creates a collection of unvisited nodes
        Vertex v1 = getVertex(start);
        Vertex v2 = getVertex(end);
        Vertex currentNode;
        ArrayList<Vertex> unvisitedNodes = new ArrayList<Vertex>();

       //PART 1 - calculate the distances, set the pi´s

        /* 1. assign to every node except the starting node the distance value of infinity
          2. set initial Node as current, mark all others as unvisited, create a set of all unvisited Nodes
        */
        for (Vertex v : vertices) {
            if (v != v1) v.setDistance(Integer.MAX_VALUE);
            unvisitedNodes.add(v);
        }

        /*3. calculate Distance to the first neghbours of the startingNode,
        remove them from the unvisited Set, when the distance has been calculated*/

        currentNode = v1;
        while (!unvisitedNodes.isEmpty()) {
            unvisitedNodes.remove(currentNode);
            for (Vertex v : getNeighbors(currentNode)) {
                int currentWeight = getEdge(currentNode, v).getWeight();
                if (currentWeight + currentNode.getDistance() < v.getDistance()) {
                    v.setDistance(currentWeight + currentNode.getDistance());
                    v.setPi(currentNode);
                }
            }

            //now we take the next node with the lowest calculated distance
            int smallestDistance = Integer.MAX_VALUE;
            Vertex smallestDisVertex = currentNode;
            for (Vertex v : vertices) {
                if (unvisitedNodes.contains(v) && v.getDistance() < smallestDistance) {
                    smallestDisVertex = v;
                    smallestDistance = v.getDistance();
                }
            }

            currentNode = smallestDisVertex;
        }
        /*do this again until the unvisited set isnt empty, if the new calculated distance
        on a node is higher than the one before ignore it, else change the distance parameter
        of the vertex and set the predecessor(pi) to the current node*/

        //now everything form the starting point is set & calculated, now we can calculate our fastest ways
        System.out.println("Time/Distance:" + v2.getDistance() + " | " + (double) (v2.getDistance() / 60) + " min (nur Fahrzeit)");

        //find the path by going through the Pi´s - the predecessors
        String path = "the following Path: \n";
        Vertex currentV = v2;
        while (currentV != v1) {
            path += currentV.getFullName() + "\n";
            currentV = currentV.getPi();
        }
        path += currentV.getFullName() + "\n";
        System.out.println(path);
    }

    public Edge getEdge(Vertex src, Vertex sink) {
        for (Edge e : edges) {
            if (e.getSrc() == src && e.getSink() == sink) return e;
        }
        return null;
    }

    public Vertex getVertex(String name) {
        for (Vertex v : vertices) {
            if (v.getName().equals(name)) return v;
        }
        return null;
    }

    public ArrayList<Vertex> getNeighbors(Vertex aVertex) {
        ArrayList<Vertex> result = new ArrayList<Vertex>();
        for (Edge e : edges) {
            if (e.getSrc() == aVertex) result.add(e.getSink());
        }
        return result;
    }

    /*
     * converts graph back to a textfile
     */
    public String toString() {
        return fileGraph;
    }

}
