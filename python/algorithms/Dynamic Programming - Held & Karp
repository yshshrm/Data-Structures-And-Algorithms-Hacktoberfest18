__author__ = 'Faouzi B.A'
import itertools, os
import random
import datetime

def held_karp(dists):
    """
    Notice :
    This program is the Python implementation of the Dynamic Programming applied to the TSP based on the held & Karp algorithm 
    and using the Bitmask concept to optmize data structure for processing
    
    Input Format : 
    The program offers tow ways of introducing the data :
    1. Reading from CSV files.
    2. Generating random distances.
    
    Parameters:
        dists: Distance matrix

    Returns:
        (cout : cost, chemin : path)
    """
    n = len(dists)

    # Mappe chaque sous-ensemble des noeuds au coût pour atteindre ce sous-ensemble, ainsi
    # que le noeud par lequel il est passé avant d'atteindre ce sous-ensemble.
    # Les sous-ensembles de nœuds sont représentés par des bits.
    C = {}

    # Le cout de transition
    for k in range(1, n):
        C[(1 << k, k)] = (dists[0][k], 0)

    # Itérer les sous-ensembles de longueur croissante et stocker les résultats intermédiaires
    # en mode de programmation dynamique classique

    for subset_size in range(2, n):
        for subset in itertools.combinations(range(1, n), subset_size):
            # Définir des bits pour tous les nœuds de ce sous-ensemble
            bits = 0
            for bit in subset:
                bits |= 1 << bit

            # Trouver le coût le plus bas pour accéder à ce sous-ensemble

            for k in subset:
                prev = bits & ~(1 << k)

                res = []
                for m in subset:
                    if m == 0 or m == k:
                        continue
                    res.append((C[(prev, m)][0] + dists[m][k], m))
                C[(bits, k)] = min(res)

    # Nous sommes intéressés par tous les bits sauf le moins significatif (l'état de départ)

    bits = (2 ** n - 1) - 1

    # Calcul du cout optimal
    res = []
    for k in range(1, n):
        res.append((C[(bits, k)][0] + dists[k][0], k))
    opt, parent = min(res)

    # Retour arrière pour trouver le chemin complet

    path = []
    for i in range(n - 1):
        path.append(parent)
        new_bits = bits & ~(1 << parent)
        _, parent = C[(bits, parent)]
        bits = new_bits

    # Ajouter un état de démarrage implicite

    path.append(0)

    return opt, list(reversed(path))


def generate_distances(n):
    dists = [[0] * n for i in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            dists[i][j] = dists[j][i] = random.randint(1, 99)

    return dists


def read_distances(filename):
    dists = []
    i = 0
    APP_ROOT = os.path.dirname(os.path.abspath(__file__))
    filename = os.path.join(APP_ROOT, filename)
    with open(filename, 'r') as f:
        for line in f:
            if i == 0:
                n=len(line.split(',')) # n = len(line.split(' '))
                dists = [[0] * n for i in range(n)]
            j = 0
            # Skip comments
            if line[0] == '#':
                continue

            for ch in map(int,line.split(',')): #map(int, line.split(' ')):
                #dists[i][j] = ch  # Asymetrique
                dists[i][j] = ch # Cas du symmetrique
                dists[j][i] = ch
                #dists[n-i-1][n-j-1] = ch

                j = j + 1
            i = i + 1

            # dists.append(map(int, map(str.strip, line.split(','))))

    return dists

def launch(type, n):

    if type==1:
        if n==1 : dists = read_distances("./burma.csv")
        if n==2 : dists = read_distances("./gr17.csv")
        if n==3 : dists = read_distances("./gr21.csv")
        if n==4 : dists = read_distances("./gr24.csv")
    else:
        dists = generate_distances(int(n))
    #for i in range(5,21):
    time2 = datetime.datetime.now()
    chemin = held_karp(dists)
    return (datetime.datetime.now() - time2), chemin



if __name__ == '__main__':
    
    # Uncomment according to the file wanted, or just generate a ixi distance matrix.
    #dists = read_distances("./burma.csv")
    #dists = read_distances("./gr17.csv")
    #dists = read_distances("./gr21.csv")
    #dists = read_distances("./gr24.csv")
    
    dists = generate_distances(20) # For example, a matrix of 20x20
    print(held_karp(dists))

