from collections import defaultdict


class Graph:
    def __init__(self, numberOfNode):
        self.graph = defaultdict(list)
        self.visited = [False] * numberOfNode

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFS(self, node):
        # We will be using a stack which pops the last element added to the stack
        # FILO; First in last out
        stack = []
        stack.append(node)
        self.visited[node] = True

        while stack:
            currentNode = stack.pop()
            print currentNode
            children = self.graph[currentNode]

            for i in range(len(children)):
                childNode = children[i]
                if not self.visited[childNode]:
                    stack.append(childNode)
                    self.visited[childNode] = True


if __name__ == "__main__":
    graph = Graph(7)
    graph.addEdge(0, 1)
    graph.addEdge(0, 2)
    graph.addEdge(0, 3)
    graph.addEdge(3, 4)
    graph.addEdge(2, 5)
    graph.addEdge(5, 6)

    print "Depth First Search starting from vertex 0:"
    graph.DFS(0)

# Graph with 7 vertices:
#      0
#    / | \
#  1   2  3
#      |  |
#      5  4
#      |
#      6
#
# DFS of the graph: 0 3 4 2 5 6 1