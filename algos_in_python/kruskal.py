import sys
sys.setrecursionlimit(9500)

class Graph:

    def __init__(self,vertices):
        self.V=len(vertices)
        self.graph=[]

    def addedge(self,u,v,w):
        self.graph.append([u,v,w])
    
    def find(self,parent,i):
        if(parent[i]==i):
            return i
        else:
            return self.find(parent,parent[i])
    def union(self,parent,rank,x,y):
        x_set=self.find(parent, x)
        y_set=self.find(parent,y)

        if(rank[x_set]<rank[y_set]):
            parent[x_set]=y_set
        elif(rank[x_set]>rank[y_set]):
            parent[y_set]=x_set

        else:
            parent[y_set]=x_set
            rank[x_set]+=1

    def weight_key(self,tup):
        return tup[2],tup[0],tup[1]

    def KruskalMST(self):
        result=[]

       

        self.graph.sort(key=self.weight_key)
        parent=[]
        rank=[]

        for i in range(self.V):
            parent.append(i)
            rank.append(0)

        e=0
        i=0
        while(e<self.V-1):
        
            u,v,w=self.graph[i]
            i+=1
            x=self.find(parent, u)
            y=self.find(parent, v)
            if(x!=y):
                e+=1
                result.append([u,v,w])
                self.union(parent, rank, x, y)
        for u,v,weight  in result: 
            print ("%d -- %d == %d" % (u,v,weight))

e=int(input("Enter no. of edges :: "))
v=int(input("Enter no. of vertices :: "))
vertices=[]
for i in range(v):
    vertices.append(i)

g=Graph(vertices)

print("Now, enter edges as src, dest, and weight :: \n")
for i in range(e):
    print()
    u=int(input("Enter src :: "))
    v=int(input("Enter dest :: "))
    w=int(input("Enter weight :: "))
    g.addedge(u, v, w)


g.KruskalMST()
