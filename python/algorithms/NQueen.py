n = int(input("Enter the number of Queens : "))
Queen = [i for i in range(n)]

def place(i, j):
    for k in range(i):
        if (Queen[k] == j or abs(Queen[k]-j) == abs(i-k)):
            return False
    return True

def print_queen():
    print("\nPlaces of Queens\n|", end="")
    for i in range(n):
        for j in range(Queen[i]):
            print("  |", end="")
        print("Q |", end="")
        for j in range(n-Queen[i]-1):
            print("  |", end="")
        if(not i == n-1):
            print("\n|", end="")
    print()
    
def n_queen(i):
    if i<n:
        for j in range(n):
            if(place(i, j)):
                Queen[i] = j
                if (i == n-1):
                    print_queen()
                else:
                    n_queen(i+1)

n_queen(0)