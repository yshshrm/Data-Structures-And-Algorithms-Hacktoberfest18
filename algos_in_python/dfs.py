class Graph:
    def __init__(self,v):
        self.V=v
        self.graph={new_list:[] for new_list in range(v)}

    def addedge(self,u,v):
        self.graph[u].append(v)
    
    def depth_first(self,visited,start):
        visited[start]=True
        print(start, end=" ")

        for i in self.graph[start]:
            if(visited[i]==False):
                self.depth_first(visited, i)

    
    def DFS(self,start):
        visited=[False]*self.V

        self.depth_first(visited,start)

e=int(input("Enter no of edgs :: "))
v=int(input("Enter no of vertices :: "))

g=Graph(v)

print("Now, enter edges :: ")

for i in range(e):
    print()
    u=int(input("Enter src :: "))
    v=int(input("Enter dest :: "))
    g.addedge(u,v)

g.DFS(2)

