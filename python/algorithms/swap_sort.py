# https://de.wikipedia.org/wiki/Swap-Sort

def swap_sort(sortme):
    index = 0
    while index < len(sortme) - 1:
        new_index = sum(x < sortme[index] for x in sortme)
        if index == new_index:
            index += 1
        else:
            sortme[index], sortme[new_index] = sortme[new_index], sortme[index]

def main():
    arr = [9, 40, 15, 7, 8, 10]
    swap_sort(arr)
    print(arr)
            
if __name__ == "__main__":
    main()
