
def bubble_sort(ls):
    for i in range(0, len(ls) - 1):
        for j in range(0, len(ls) - 1 - i):
            if ls[j] > ls[j + 1]:
                tmp = ls[j]
                ls[j] = ls[j + 1]
                ls[j + 1] = tmp

if __name__ == '__main__':
    arr = [2, 4, 5, 7, 8, 10]
    bubble_sort(arr)
    print(arr)
