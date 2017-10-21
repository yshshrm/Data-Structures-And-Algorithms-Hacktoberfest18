import java.util.Collection;
import java.util.HashMap;
import java.util.Set;

public class Graphs {
	class Vertex {
		String name;
		HashMap<Vertex, Integer> neighbors;

		Vertex(String name) {
			this.name = name;
			this.neighbors = new HashMap<>();
		}

		public boolean equals(Object other) {
			Vertex ov = (Vertex) other;
			return this.name.equals(ov.name);
		}

		public int hashCode() {
			return this.name.hashCode();
		}

		public void display() {
			String rv = "";
			rv = rv + this.name + "=>";
			Set<Vertex> nbrs = this.neighbors.keySet();
			for (Vertex nbr : nbrs) {
				rv = rv + nbr.name + "(" + this.neighbors.get(nbr) + "), ";
			}
			rv = rv + "END";
			System.out.println(rv);

		}
	}

	private HashMap<String, Vertex> vertices;

	Graphs() {
		this.vertices = new HashMap<>();
	}

	public int numberOfVertices() {
		return this.vertices.size();
	}

	public void addVertex(String name) {
		if (this.vertices.containsKey(name)) {
			return;
		}
		Vertex vtx = new Vertex(name);
		this.vertices.put(name, vtx);
	}

	public void removeVertex(String name) {
		if (!this.vertices.containsKey(name)) {
			return;
		}
		Vertex vtx = this.vertices.get(name);
		Set<Vertex> nbrs = vtx.neighbors.keySet();
		for (Vertex nbr : nbrs) {
			nbr.neighbors.remove(vtx);
		}
		this.vertices.remove(name);

	}

	public int numberOfEdges() {
		int size = 0;
		Collection<Vertex> vtces = this.vertices.values();
		for (Vertex vtx : vtces) {
			size = size + vtx.neighbors.size();
		}
		return size / 2;

	}

	public void addEdge(String v1, String v2, int weight) {
		Vertex vtx1 = this.vertices.get(v1);
		Vertex vtx2 = this.vertices.get(v2);
		if (vtx1 == null || vtx2 == null || vtx1.neighbors.containsKey(vtx2))
			return;
		vtx1.neighbors.put(vtx2, weight);
		vtx2.neighbors.put(vtx1, weight);

	}

	public void removeEdge(String v1, String v2) {
		Vertex vtx1 = this.vertices.get(v1);
		Vertex vtx2 = this.vertices.get(v2);
		if (vtx1 == null || vtx2 == null || !vtx1.neighbors.containsKey(vtx2))
			return;
		vtx1.neighbors.remove(vtx2);
		vtx2.neighbors.remove(vtx1);
	}

	public void display() {
		Set<String> vtces = this.vertices.keySet();
		for (String vtxname : vtces) {
			Vertex vtx = this.vertices.get(vtxname);
			vtx.display();
		}
		System.out.println("------------------------------");
	}

	public boolean hasPathRec(String v1, String v2) {
		Vertex vtx1 = this.vertices.get(v1);
		Vertex vtx2 = this.vertices.get(v2);
		if (vtx1 == null || vtx2 == null)
			return false;
		HashMap<Vertex, Boolean> explored = new HashMap<>();
		return this.hasPathRec(vtx1, vtx2, explored);
	}

	private boolean hasPathRec(Vertex vtx1, Vertex vtx2, HashMap<Vertex, Boolean> explored) {
		boolean flag;
		if (vtx1.neighbors.containsKey(vtx2))
			return true;
		if (explored.containsKey(vtx1))
			return false;
		explored.put(vtx1, true);
		Set<Vertex> nbrs = vtx1.neighbors.keySet();
		for (Vertex nbr : nbrs) {
			flag = hasPathRec(nbr, vtx2, explored);
			if (flag)
				return true;
		}
		return false;

	}

	public boolean isConnected() {
		Set<String> keys = this.vertices.keySet();
		for (String key : keys) {
			for (String vtx : keys)
				if (!hasPathRec(key, vtx)) {
					return false;
				}

		}
		return true;

	}

}
