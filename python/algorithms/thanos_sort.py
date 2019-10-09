n = int(input())

array = [int(i) for i in input().split()]

arrays = []

'''
A sorting algorithm that removes half of an array's elements at a time until the array is sorted.
'''

def thanosSort(array):

    if (array == sorted(array)):
        arrays.append(array)
        return

    firstPart = array[0:len(array) // 2]

    secondPart = array[len(array) // 2:len(array)]

    thanosSort(firstPart)
    thanosSort(secondPart)

thanosSort(array)

largerArray = []

for e in arrays:
    if len(largerArray) < len(e):
        largerArray = e

print(largerArray)
