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

    
    def top_sort(self):
        indegree = self.indeg()
        trail = []
        while (len(trail)!=self.size):
            zero = indegree.index(0)
            trail.append(zero)
            indegree[zero] = -1
            for vertices in self.adjacent_vertices(zero):
                indegree[vertices] = indegree[vertices]-1
        return trail

g = Graph(6)
g.directed = True
g.addEdge(5, 2); 
g.addEdge(5, 0); 
g.addEdge(4, 0); 
g.addEdge(4, 1); 
g.addEdge(2, 3); 
g.addEdge(3, 1); 
print(g.top_sort())
    
