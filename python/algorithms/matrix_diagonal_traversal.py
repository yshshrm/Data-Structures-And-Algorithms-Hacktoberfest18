def traverse_matrix_diagonally(matrix):
    if not matrix:
        return []

    nums_group = {}
    max_index_sum = -1
    for r in range(len(matrix)):
        for c in range(len(matrix[0])):
            index_sum = c + r
            element = matrix[r][c]

            # each diagonal has same index_sum
            if index_sum in nums_group:
                nums_group[index_sum].append(element)
            else:
                nums_group[index_sum] = [element]

            # updates max_index_sum
            if index_sum > max_index_sum:
                max_index_sum = index_sum
    
    result = []
    for s in range(max_index_sum + 1):
        result.append(nums_group[s])
        
    return result
    
if __name__ == '__main__':
    test = [
            [1, 2, 3], 
            [4, 5, 6], 
            [7, 8, 9]
        ]
    print(traverse_matrix_diagonally(test))
