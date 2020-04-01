import sys

class Graph:
    
    def __init__(self,vertices):
        self.V=(vertices)
        self.graph=[[ 0 for i in range(vertices)]for j in range(vertices) ]

    def addedge(self,u,v,w):
        self.graph[u][v]=w
        self.graph[v][u]=w
    
    def minKey(self,key,mstSet):
        min=sys.maxsize
        minKey=0
        for v in range(self.V):
            if(mstSet[v]==False and key[v]<min):
                min=key[v]
                minKey=v
        return minKey
    def printMST(self,parent):
        print("Prim's MST contains edges : ")
        print("Edge \tWeight")
        for i in range(1,self.V):
            print (str(parent[i])+"--"+str(i)+"\t"+str(self.graph[i][parent[i]]))

    def primMST(self):
        
        mstSet=[False]*self.V
        parent=[None]*self.V
        key= [sys.maxsize]*self.V

        key[0]=0
        parent[0]=-1

        for v in range(self.V):

            u=self.minKey(key, mstSet)
            mstSet[u]=True

            for i in range(self.V):
                if(self.graph[v][i]>0 and mstSet[i]==False and key[i]>self.graph[v][i]):
                    key[i]=self.graph[v][i]
                    parent[i]=v
        
        self.printMST(parent)



e=int(input("Enter no. of edges :: "))
v=int(input("Enter no of vertices :: "))
g = Graph(v) 
print("Now, Enter Edges :: ")

for i in range(e):
    print()
    u=int(input("Enter src. "))
    v=int(input("Enter dest "))
    w=int(input("Enter weight "))
    g.addedge(u, v, w)
print(g.graph)
g.primMST()