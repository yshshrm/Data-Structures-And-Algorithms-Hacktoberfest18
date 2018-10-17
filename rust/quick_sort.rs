/// Performs the quick sort algorithm on a given vector.
fn quick_sort<T: Ord>(mut arr: Vec<T>) -> Vec<T> {
    //Empty vector is already sorted
    if arr.len() <= 1 {
        return arr;
    }

    // Get the pivot
    let pivot = pivot(&mut arr);

    //Partition the vector around the pivot
    let (mut smaller, equals, mut larger) = partition(arr, pivot);

    // Sort each vector from the partition
    smaller = quick_sort(smaller);
    larger = quick_sort(larger);

    // Concatenate the three vectors into one
    concat(smaller, equals, larger)
}

/// Gets the 'pivot' element from a vector. Currently
/// just selects the first element as the pivot, therefore
/// requires the vector is non-empty.
/// Provided to allow for different implementations
/// for picking the pivot (i.e using the median value)
fn pivot<T>(arr: &mut Vec<T>) -> T {
    arr.remove(0)
}

/// Partitions the given vector around the given pivot, i.e.
/// puts all elements that are smaller than the pivot into one
/// vector, all the elements that are equal into another and all 
/// elements that are larger than the pivot into another. Returns
/// a tuple containing the vector of smaller values, the vector of 
/// equal values and the vector of larger values (in that order).
fn partition<T: Ord>(arr: Vec<T>, pivot: T) -> (Vec<T>, Vec<T>, Vec<T>) {
    let mut smaller = vec![];
    let mut larger = vec![];
    let mut equals = vec![];

    for entry in arr {
        if entry < pivot {
            smaller.push(entry);
        } else if entry > pivot {
            larger.push(entry);
        } else {
            equals.push(entry)
        }
    }
    equals.push(pivot);

    (smaller, equals, larger)
}

/// Concatenates three vectors together into one
fn concat<T>(mut smaller: Vec<T>, mut equals: Vec<T>, mut larger: Vec<T>) -> Vec<T> {
    smaller.append(&mut equals);
    smaller.append(&mut larger);
    
    smaller
}
