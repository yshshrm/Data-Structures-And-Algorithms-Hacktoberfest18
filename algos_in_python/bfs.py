class Graph:
    def __init__(self,v):
        self.V=v
        self.graph={new_list:[] for new_list in range(v)}

    def addedge(self,u,v):
        self.graph[u].append(v)

    def bfs(self,start):
        visited=[False]*self.V

        queue=[]

        queue.append(start)
        visited[start]=True

        while queue:

            start=queue.pop(0)
            print( start, end=" ")

            for i in self.graph[start]:
                if(visited[i]==False):
                    visited[i]=True
                    queue.append(i)

    
e=int(input("Enter no of edgs :: "))
v=int(input("Enter no of vertices :: "))

g=Graph(v)

print("Now, enter edges :: ")

for i in range(e):
    print()
    u=int(input("Enter src :: "))
    v=int(input("Enter dest :: "))
    g.addedge(u,v)

g.bfs(2)
