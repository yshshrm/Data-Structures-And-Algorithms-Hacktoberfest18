# https://en.wikipedia.org/wiki/Disjoint-set_data_structure

class DisjointSet:
    def __init__(self, n):
        self.rank = [0] * n
        self.parent = range(n)

    def find_set(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find_set(self.parent[i])
        return self.parent[i]
    
    def is_same_set(self, i, j):
        return self.find_set(i) == self.find_set(j)
    
    def union_set(self, i, j):
        if self.is_same_set(i, j):
            return
        
        x = self.find_set(i)
        y = self.find_set(j)

        if self.rank[x] < self.rank[y]:
            x, y = y, x

        self.parent[y] = x

        if self.rank[x] == self.rank[y]:
            self.rank[x] += 1

def main():
    ds = DisjointSet(10)

    ds.union_set(1, 2)

    print(ds.find_set(1))
    print(ds.find_set(2))
    print(ds.find_set(6))
    
    print(ds.is_same_set(1, 2))
    print(ds.is_same_set(1, 3))

if __name__ == "__main__":
    main()
