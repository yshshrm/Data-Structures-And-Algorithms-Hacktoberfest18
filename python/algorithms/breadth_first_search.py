from collections import deque
import numpy as np
from copy import deepcopy
import math
class Graph:
    """
    Implementation of a graph with Adjacency Matrix
    """
    def __init__(self,size,directed = False):
        self.size = size
        self.matrix = [[0 for i in range(self.size)] for j in range(self.size)]
        self.directed = directed
        self.Time = 0
        self.color = {i:"white" for i in range(self.size)}
        self.parent = [-1 for i in range(self.size)]
        self.time = [[0,0] for i in range(self.size)]

    def has_vertex(self,i):
        return i>=0 and i<self.size

    def addEdge(self,i,j,weight=1):
        if self.has_vertex(i) and self.has_vertex(j):
            if self.directed:
                self.matrix[i][j] = weight
            else:
                self.matrix[i][j] = weight
                self.matrix[j][i] = weight

    def delEdge(self,i,j):
        if self.directed:
            self.matrix[i][j] = 0
        else:
            self.matrix[i][j] = 0
            self.matrix[j][i] = 0

    def adjacent_vertices(self,i):
        if self.has_vertex(i):
            w = []
            for j in range(self.size):
                if self.matrix[i][j] != 0:
                    w.append(j)
            return w

    def indeg(self):
        indegree = [0 for i in range(self.size)]
        for i in range(self.size):
            l = self.adjacent_vertices(i)
            for j in l:
                indegree[j] =  indegree[j] + 1
        return indegree

        
    def bfs_colors(self,s):
        color = {i:"white" for i in range(self.size)}
        parent = [-1 for i in range(self.size)]
        distance = [500 for i in range(self.size)]

        color[s] = "gray"
        distance[s] = 0

        qu = deque()
        qu.append(s)
        while len(qu)>0:
            u = qu.popleft()
            for v in self.adjacent_vertices(u):
                if color[v] == "white":
                    color[v] = "gray"
                    distance[v] = distance[u] + 1
                    parent[v] = u
                    qu.append(v)
            color[u] = "black"
        print("Color",color)
        print("Parent",parent)
        print("Distance",distance)

    def bfs_iterative(self,s):
        seen = set({})
        stack = deque([s])
        trail = []
        while len(stack)>0:
            u = stack.popleft()
            if u in seen:
                continue
            seen.add(u)
            trail.append(u)
            for v in self.adjacent_vertices(u):
                stack.append(v)
        return trail

## Test Cases
##g1 = Graph(4)
##g1.directed = False
##g1.addEdge(0, 1)
##g1.addEdge(0, 2)
##g1.addEdge(1, 2)
##g1.addEdge(2, 3)
##g1.bfs_colors()

##g2 = Graph(3)
##g2.directed = False
##g2.addEdge(0, 1)
##g2.addEdge(1, 2)
##g2.addEdge(2, 0)
##g2.bfs_iterative()
            


            
