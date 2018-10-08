# How does heapsort works: https://en.wikipedia.org/wiki/Heapsort

def heapsort(list_of_elements):
    list_size = len(list_of_elements) - 1
    least_parent = int(list_size / 2)
    for i in range(least_parent, -1, -1):
        move_down(list_of_elements, i, list_size)

    for i in range(list_size, 0, -1):
        if list_of_elements[0] > list_of_elements[i]:
            swap(list_of_elements, 0, i)
            move_down(list_of_elements, 0, i - 1)


def move_down(l, first, last):
    largest = 2 * first + 1
    while largest <= last:
        # right child greater than left child
        # and lesser than parent
        if largest < last and l[largest] < l[largest + 1]:
            largest += 1
        # right child bigger than parent
        elif l[largest] > l[first]:
            swap(l, largest, first)
            first = largest
            largest = 2 * first + 1
        else:
            return  # force exit


def swap(tgt_list, i, j):
    tgt_list[i], tgt_list[j] = tgt_list[j], tgt_list[i]


if __name__ == '__main__':
    test_list = [8, 5, 3, 1, 9, 6, 0, 7, 4, 2, 5]
    print(f'Before sorting: {test_list}')
    heapsort(test_list)
    print(f'After sorting: {test_list}')
