# Program to find maximum contiguous sum in given list using Kadene's Algorithm in O(n).

def kadenesAlgo(lst):
	sum = ctr = lst[0]
	n = len(lst)
	for i in range(1, n):
		sum = max(lst[i], sum + lst[i])
		ctr = max(ctr, sum)
	return ctr

def main():
	print("Enter the elements of list separated by space: ")
	lst = [int(x) for x in input().split()]
	print("Maximum contiguous sum is: " + str(kadenesAlgo(lst)))

if __name__ == '__main__':
	main()
