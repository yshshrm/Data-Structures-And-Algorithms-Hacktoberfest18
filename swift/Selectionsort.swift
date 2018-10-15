func selsrtI(lst)
    max = length(lst) - 1

    for i from 0 to max
        key = lst[i]
        keyj = i

        for j from i+1 to max
            if lst[j] < key
                key = lst[j]
                keyj = j

        lst[keyj] = lst[i]
        lst[i] = key

    return lst

end func

