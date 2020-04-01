def generate_pascal_triangle(num_row):
    if num_row == 0:
        return []
    elif num_row == 1:
        return [[1]]
    elif num_row == 2:
        return [[1],[1,1]]
    
    result = [[1],[1,1]]
    previous_row = [1, 1]
    while num_row != 2:
        temp = [1]
        for i in range(len(previous_row) - 1):
            temp.append(previous_row[i] + previous_row[i+1])
        temp.append(1)
        result.append(temp)
        previous_row = temp
        num_row -= 1

    return result
    
if __name__ == '__main__':
    print(generate_pascal_triangle(10))