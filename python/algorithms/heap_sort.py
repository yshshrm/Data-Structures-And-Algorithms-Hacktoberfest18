from random import *

def generate_vector(size, intervals):
    random_vector = []
    for i in range(size):
        new_element = randint(0,intervals)
        random_vector.append(new_element)
    return random_vector

def heapfy(vector,index):
    bigger = index
    left = 2*index
    right = 2*index+1

    if(vector[0] >= right):
        if(vector[index] < vector[right]):
            bigger = right
        if(vector[bigger] < vector[left]):
            bigger = left
        if(bigger != index):
            vector[bigger],vector[index] = vector[index],vector[bigger]
            heapfy(vector,bigger)
    elif(vector[0] >= left): 
        if(vector[index] < vector[left]):
            vector[left],vector[index] = vector[index],vector[left]
            heapfy(vector,left)

def buildHeap(vector):
    vector = [len(vector)] + vector
    for i in range(int(len(vector)/2),0,-1):
        heapfy(vector,i)
    return vector

def heapsort(vector):
    vector = buildHeap(vector)
    for i in range(len(vector)-1,0,-1):
        vector[1], vector[i] = vector[i] , vector[1]
        vector[0] -= 1
        heapfy(vector,1)
    vector.pop(0)
    return vector

if __name__ == '__main__': 
    vec = generate_vector(10,100)
    print('Random vector: ' + str(vec))
    vec = heapsort(vec)
    print('Vector in order: '+ str(vec))
