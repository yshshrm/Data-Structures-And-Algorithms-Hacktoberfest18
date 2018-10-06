# Call the various traversal functions iterative or recursive
# Functions will be called with input argument root and result=[]
# Output will be improved list variable result passed
def preorder_recursive(root,result):
    if not root:
        return
    result.append(root.data)
    preorder_recursive(root.left,result)
    preorder_recursive(root.right,result)
def preorder_iterative(root,result):
    if not root:
        return
    stack = []
    stack.append(root)
    while stack:
        node = stack.pop()
        result.append(node.data)
        if node.right: stack.append(node.right)
        if node.left: stack.append(node.left)

def inorder_recursive(root,result):
    if not root:
        return
    inorder_recursive(root.left,result)
    result.append(root.data)
    inorder_recursive(root.right,result)
def inorder_iterative(root,result):
    if not root:
        return
    stack = []
    node = root
    while stack or node:
        if node:
            stack.append(node)
            node = node.left
        else:
            node = stack.pop()
            result.append(node.data)
            node = node.right


def postorder_recursive(root,result):
    if not root:
        return
    postorder_recursive(root.left,result)
    postorder_recursive(root.right,result)
    result.append(root.data)
def postorder_iterative(root,result):
    if not root:
        return
    visited = set()
    stack = []
    node = root
    while stack or node:
        if node:
            stack.append(node)
            node = node.left
        else:
            node = stack.pop()
            if node.right and not node.right in visited:
                stack.append(node)
                node = node.right
            else:
                visited.add(node)
                result.append(node.data)
                node = None

import queue
def levelorder(root,result):
    if root is None:
        return
    q = queue.Queue()
    q.put(root)
    node = None
    while not q.empty():
        node = q.get()
        result.append(node.getData())
        if node.getLeft() is not None:
            q.put(node.getLeft())
        if node.getRight() is not None:
            q.put(node.getRight())
