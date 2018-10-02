package Graph;

import java.util.ArrayList;
import java.util.HashMap;


public class Graph {

	private class Vertex {
		HashMap<String, Integer> nghbrs = new HashMap<>();
	}

	HashMap<String, Vertex> vertices = new HashMap<>();

	public int numVetex() {
		return vertices.size();
	}

	public boolean containsVertex(String vname) {
		return vertices.containsKey(vname);
	}

	public void addVertex(String vname) {
		Vertex vtx = new Vertex();
		vertices.put(vname, vtx);
	}

	public void removeVertex(String vname) {

		Vertex vtx = vertices.get(vname);
		ArrayList<String> nbrnames = new ArrayList<>(vtx.nghbrs.keySet());

		for (String nbrname : nbrnames) {

			Vertex vtxnbr = vertices.get(nbrname);
			vtxnbr.nghbrs.remove(vname);
		}

		vertices.remove(vname);

	}

	public int numEdges() {

		ArrayList<String> vnames = new ArrayList<>(vertices.keySet());
		int ans = 0;

		for (String vname : vnames) {

			Vertex vtx = vertices.get(vname);
			ans += vtx.nghbrs.size();
		}

		return ans / 2;
	}

	public boolean containsEdge(String vname1, String vname2) {

		Vertex vtx1 = vertices.get(vname1);
		Vertex vtx2 = vertices.get(vname2);

		if (vtx1 == null || vtx2 == null || !vtx1.nghbrs.containsKey(vname2)) {
			return false;
		}

		return true;
	}

	public void addEdge(String vname1, String vname2, int cost) {

		Vertex vtx1 = vertices.get(vname1);
		Vertex vtx2 = vertices.get(vname2);

		if (vtx1 == null || vtx2 == null || vtx1.nghbrs.containsKey(vname2)) {
			return;
		}

		vtx1.nghbrs.put(vname2, cost);
		// vtx2.nghbrs.put(vname1, cost);
	}

	public void removeEdge(String vname1, String vname2) {

		Vertex vtx1 = vertices.get(vname1);
		Vertex vtx2 = vertices.get(vname2);

		if (vtx1 == null || vtx2 == null || !vtx1.nghbrs.containsKey(vname2)) {
			return;
		}

		vtx1.nghbrs.remove(vname2);
		vtx2.nghbrs.remove(vname1);
	}

	public void display() {

		System.out.println("------------------");
		ArrayList<String> vnames = new ArrayList<>(vertices.keySet());

		for (String vname : vnames) {

			String str = vname + " => ";

			Vertex vtx = vertices.get(vname);
			str += vtx.nghbrs;

			System.out.println(str);
		}
		System.out.println("------------------");

	}

	// prims -> minimum spanning tree
	private class PrimsPair implements Comparable<PrimsPair> {

		String vname;
		String acqVertexName;
		Vertex vtx;
		int cost;

		@Override
		public int compareTo(PrimsPair other) {
			return other.cost - this.cost;
		}
	}

	public Graph prims() {

		// create a mst
		Graph mst = new Graph();

		HeapGeneric<PrimsPair> heap = new HeapGeneric<>();
		HashMap<String, PrimsPair> map = new HashMap<>();
		HashMap<String, Boolean> processed = new HashMap<>();

		ArrayList<String> keys = new ArrayList<>(this.vertices.keySet());

		// make pairs and put in heap
		for (String key : keys) {
			PrimsPair np = new PrimsPair();
			np.vname = key;
			np.vtx = vertices.get(key);
			np.cost = Integer.MAX_VALUE;
			np.acqVertexName = null;

			heap.add(np);
			processed.put(np.vname, true);
			map.put(key, np);
		}

		// til the heap is not empty keep on doing work
		while (!heap.isEmpty()) {

			// remove a pair
			PrimsPair rp = heap.remove();
			processed.remove(rp.vname);

			// if acq vertex is null, add a vertx only
			if (rp.acqVertexName == null) {
				mst.addVertex(rp.vname);
			} else {
				mst.addVertex(rp.vname);
				mst.addEdge(rp.vname, rp.acqVertexName, rp.cost);
			}

			// get nbrs
			ArrayList<String> nbrs = new ArrayList<>(rp.vtx.nghbrs.keySet());

			// loop on nbrs
			for (String nbr : nbrs) {

				// process only the one which are in heap
				if (processed.containsKey(nbr)) {
					PrimsPair nbrPair = map.get(nbr);

					// get the old cost
					int oc = nbrPair.cost;
					int nc = rp.vtx.nghbrs.get(nbr);

					// if new cost is smaller than old cost then update the cost
					if (nc < oc) {
						nbrPair.cost = nc;
						nbrPair.acqVertexName = rp.vname;

						// update the priority in heap
						heap.updatePriority(nbrPair);
					}
				}
			}
		}

		return mst;
	}

	// dijkstra -> single source shortest path, but can't work with -ve weight
	// edges
	public class DijkstraPair implements Comparable<DijkstraPair> {

		String vname;
		String psf;
		Vertex vtx;
		int cost;

		@Override
		public int compareTo(DijkstraPair other) {
			return other.cost - this.cost;
		}

		@Override
		public String toString() {
			return this.cost + " via " + this.psf + "\n";
		}

	}

	public HashMap<String, DijkstraPair> Dijkstra(String src) {

		HashMap<String, DijkstraPair> map = new HashMap<>();
		HeapGeneric<DijkstraPair> heap = new HeapGeneric<>();

		// processed will keep track of vertex which are present in heap
		HashMap<String, Boolean> processed = new HashMap<>();

		// get all the vertex names present in graph
		ArrayList<String> keys = new ArrayList<>(this.vertices.keySet());

		// make pairs and put in heap, with the cost of src vertex as 0
		for (String key : keys) {
			DijkstraPair np = new DijkstraPair();
			np.vname = key;
			np.vtx = vertices.get(key);
			np.psf = "";
			np.cost = Integer.MAX_VALUE;

			// if present key is src, cost of src vertex will be 0
			if (key.equals(src)) {
				np.psf = key;
				np.cost = 0;
			}

			heap.add(np);
			map.put(key, np);

			// update the processed, bcz processed was keeping track of nodes which are
			// present in heap
			processed.put(key, true);
		}

		// till the heap is not empty keep on removing pairs
		while (!heap.isEmpty()) {

			// remove the pair from heap
			DijkstraPair rp = heap.remove();

			// update the processed hashmap
			processed.remove(rp.vname);

			// loop on nbrs
			ArrayList<String> nbrs = new ArrayList<>(rp.vtx.nghbrs.keySet());

			for (String nbr : nbrs) {

				// process only those nbrs which are present in heap
				if (processed.containsKey(nbr)) {
					DijkstraPair nbrPair = map.get(nbr);

					int oc = nbrPair.cost;
					int nc = rp.cost + rp.vtx.nghbrs.get(nbr);

					// if new cost is less than old cost then update the cost
					if (nc < oc) {
						nbrPair.cost = nc;
						nbrPair.psf = rp.psf + nbr;

						// update the priority of the updated node in heap
						heap.updatePriority(nbrPair);
					}
				}
			}
		}

		return map;

	}

	// bellman ford -> single source shortest path, can work with -ve weight edges,
	// but can't work with cycle having -ve weights
	public ArrayList<EdgePair> getAllEdges() {

		ArrayList<EdgePair> ans = new ArrayList<>();

		ArrayList<String> keys = new ArrayList<>(vertices.keySet());

		for (String key : keys) {

			Vertex vtx = vertices.get(key);
			ArrayList<String> nbrs = new ArrayList<>(vtx.nghbrs.keySet());

			for (String nbr : nbrs) {
				EdgePair ep = new EdgePair();
				ep.vname1 = key;
				ep.vname2 = nbr;
				ep.cost = vtx.nghbrs.get(nbr);

				ans.add(ep);
			}

		}

		return ans;
	}

	private class EdgePair {
		String vname1;
		String vname2;
		int cost;
	}

	public HashMap<String, Integer> BellmanFord(String src) throws Exception {

		HashMap<String, Integer> map = new HashMap<>();

		ArrayList<String> keys = new ArrayList<>(this.vertices.keySet());

		// put the src vertex with 0 cost, and other vertex with infinity cost
		for (String key : keys) {

			map.put(key, Integer.MAX_VALUE);

			// if key equals src then cost will be 0
			if (key.equals(src)) {
				map.put(key, 0);
			}

		}

		// get all the edges
		ArrayList<EdgePair> alledges = getAllEdges();

		// V is total no. of vertex in graph
		int V = vertices.size();

		// relax V-1 times bcz at max two vertex can be at V-1 distance
		for (int i = 1; i <= V - 1; i++) {

			// all the edges are relaxed
			// relax : if we have discovered an edge from u->v then compare
			// if cost(v) > cost(u) + edgecost(u,v) then update the cost of v
			// cost(v) = cost(u) + edgecost(u,v)
			for (EdgePair edge : alledges) {

				int oc = map.get(edge.vname2);
				int nc = map.get(edge.vname1) + edge.cost;

				// update the cost of v, if cost(u) + edgecost(u,v) is less than prev cost of v
				if (nc < oc) {
					map.put(edge.vname2, nc);
				}
			}
		}

		// if the weights are further reduced after relaxing Vth time then it means -ve
		// weight cycle was present
		for (EdgePair edge : alledges) {

			int oc = map.get(edge.vname2);
			int nc = map.get(edge.vname1) + edge.cost;

			System.out.println(map.get(edge.vname1) + "   " + nc);

			// if wt is further reduced then give an exception to user
			if (nc < oc) {
				throw new Exception("-ve weight cycle");
			}
		}

		return map;
	}
}
