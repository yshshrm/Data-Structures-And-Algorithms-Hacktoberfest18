def mergesort(array)
    if array.count <= 1
        return array
    end
    mid = array.count / 2
    part_a = mergesort array.slice(0, mid)
    part_b = mergesort array.slice(mid, array.count - mid)
    array = []
    index_a = 0
    index_b = 0
    while index_a < part_a.count && index_b < part_b.count
        a = part_a[index_a]
        b = part_b[index_b]
        if a <= b
            array << a
            index_a += 1
        else
            array << b
            index_b += 1
        end
    end
    while index_a < part_a.count
        array << part_a[index_a]
        index_a += 1
    end

    while index_b < part_b.count
        array << part_b[index_b]
        index_b += 1
    end

    return array
end

b = [100,485,12,3,9,8,745,120,47,523,45,20].shuffle
# Mergesort operates in new array
# So we need to reassign
arr = mergesort b
puts "After applying Mergesort "
print arr
puts