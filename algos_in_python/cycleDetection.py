#cycle detection using union find data structure


class Graph:
    def __init__(self,vertices):
        self.V=len(vertices)
        self.graph={v:[] for v in vertices}
    
    def addedge(self,u,v):
        self.graph[u].append(v)
    
    def find_parent(self,parent,i):
        if(parent[i]==-1):
            return i
        else:
            return self.find_parent(parent,parent[i])
    
    def union(self,parent,a,b):
        a_set=self.find_parent(parent, a)
        b_set=self.find_parent(parent, b)
        parent[a_set]=b_set

    def is_Cycle(self):
        parent=[-1]*self.V

        for x in self.graph:
            for y in self.graph[x]:
                a=self.find_parent(parent, x)
                b=self.find_parent(parent, y)
                if(a==b):
                    return False
                self.union(parent,a,b)
        return True


                
n=int(input("Enter the no.  of edges :: "))
v=int(input("Enter the no. of vertices :: "))
vertices=[]
print("Enter vertices now :: ")
for i in range(v):
    vertices.append(i)
g=Graph(vertices)

print("Now, enter edges :: ")

for i in range(n):
    print()
    x=int(input("Enter src :: "))
    y=int(input("Enter dest. :: "))
    g.addedge(x,y)

if(g.is_Cycle()):
        print(" Graph has no cycle ")
else:
        print("Graph has cycle")
  
                
