#bfs
from n_aryTree import *
# make tree for testing
p = Node(5)
c1 = Node(6)
c2 = Node(7)
p.add_child(c1)
p.add_child(c2)

c11 = Node(8)
c12 = Node(9)
c21 = Node(10)
c22 = Node(11)
c1.add_child(c11)
c1.add_child(c12)

c2.add_child(c21)
c2.add_child(c22)

def dfs(n):
	if (len(n.children)==0):
		print(n.data)
	else:
		print(n.data) #Print First then go deeper
		for i in range(len(n.children)):
			dfs(n.children[i])

print("\nDFS traversal gives:")
dfs(p)