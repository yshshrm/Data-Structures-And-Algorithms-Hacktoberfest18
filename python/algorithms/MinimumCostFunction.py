# Implementing a Minimum Cost Function in Python
def mcp(path, x, y):
    """
    For a matrix ```path``` that represents the paths with their costs
    (x,y) is the coordinate you have to reach from (0,0)
    You can move, left, right, diagonally down
    This definition gives the minimum cost path to reach the given coordinate
    NOTE: 0-based indexing used
    """
    if (x < 0 or y < 0): 
        import sys
        return sys.maxsize 
    elif (x == 0 and y == 0): 
        return path[x][y] 
    else: 
        return path[x][y] + min([ mcp(path, x-1, y-1), mcp(path, x-1, y), mcp(path, x, y-1)]) 
  
def main():
    # Driver program to test above functions  
    paths = [ [1, 2, 3], [4, 5, 6], [7, 8, 9] ] 
    print(mcp(paths, 2, 2)) 

if __name__ == "__main__":
    main()
