def rotate(nums, k, direction='l'):
    for i in range(k):
        if direction == 'r':
            nums.insert(0, nums.pop())
        else:
            nums.append(nums.pop(0))

if __name__ == '__main__':
    test = [1, 2, 3, 4, 5]
    print(test)
    rotate(test, 2, direction='r')
    print("After rotating 2 times to the right: ")
    print(test)
    rotate(test, 2, direction='l')
    print("After rotating 2 times to the left: ")
    print(test)
