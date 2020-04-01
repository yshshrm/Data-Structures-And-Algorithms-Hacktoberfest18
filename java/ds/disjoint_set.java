import java.util.ArrayList;

class disjoint_set {

    static class DisjointSet {
        private int[] parent, rank;
        
        public DisjointSet(int n) {
            parent = new int[n];
            rank = new int[n];

            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        private void swap(int i, int j) {
            parent[i] = parent[i] ^ parent[j];
            parent[j] = parent[i] ^ parent[j];
            parent[i] = parent[i] ^ parent[j];
        }

        public int findSet(int i) {
            if (parent[i] == i)
                return i;

            parent[i] = findSet(parent[i]);
            
            return parent[i];
        }

        public boolean isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        public void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i);
                int y = findSet(j);

                if (rank[x] < rank[y])
                    swap(x, y);
                
                parent[y] = x;
                    
                if(rank[x] == rank[y])
                    rank[x]++;
            }
        }
    }
    
    public static void main(String[] args) {
        DisjointSet disjointSet = new DisjointSet(10);

        //merge set 1 and set 4
        disjointSet.unionSet(1, 4);

        //find the set id
        System.out.println(disjointSet.findSet(1));
        System.out.println(disjointSet.findSet(2));
        System.out.println(disjointSet.findSet(4));
        
        //check membership of set
        System.out.println(disjointSet.isSameSet(1, 2));
        System.out.println(disjointSet.isSameSet(1, 4));
    }
}