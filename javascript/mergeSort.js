const merge = (left, right) => {
    let temp = []
    let i = 0, j = 0
    while (i < left.length && j < right.length) {
        if (left[i] < right[j]) temp.push(left[i++])
        else temp.push(right[j++])
    }
    for (let k=i; k < left.length; k++) {
        temp.push(left[k])
    }
    for (let k=j; k < right.length; k++) {
        temp.push(right[k])
    }
    return temp;
}

const mergeSort = (arr) => {
    if (arr.length > 1) {
        let mid = Math.floor(arr.length / 2)
        let left = arr.slice(0, mid)
        let right = arr.slice(mid)
        return merge(mergeSort(left), mergeSort(right))
    }
    return arr;
}

let test = [1, 0, 8, 4, 3, 2, 7, 5, 6]
console.log(mergeSort(test))