from math import floor


def slow_sort(array, i, j):
    """
    a really slow sorting algorithm based on multiply and surrender
    ---------------------------------
    array: list
        list of items
    i : int
        index of the first item array
    j: int
        index of the last item in array
    """
    if i >= j:
        return
    m = floor((i + j) / 2)
    slow_sort(array, i, m)
    slow_sort(array, m + 1, j)
    if array[j] < array[m]:
        array[j], array[m] = array[m], array[j]
    slow_sort(array, i, j-1)


a = [6, 53, 9, 7, 2, 3, 5, 1]
slow_sort(a, 0, len(a) - 1)
print(a)
