# To print all the binary string for a given 'n' value

def binary(n,bi):

    if (n == -1):
        print ''.join(bi)
        return
    else:
        bi[n] = str(0)
        binary(n-1, bi)
        bi[n] = str(1)
        binary(n-1, bi)


n = input()
bi = []

# Defining a list of size n with dummy values
for i in range(n):
    bi.append(-1)

binary(n-1, bi)
