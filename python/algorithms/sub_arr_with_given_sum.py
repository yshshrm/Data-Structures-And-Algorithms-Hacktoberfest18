#  find subarray with given sum in array of integers

def sub_arr_with_sum(arr, arr_len, target_sum):
	sum_dict = {}
	curr_sum = 0
	for i in xrange(0, arr_len):
		curr_sum += arr[i]
		if curr_sum == target_sum:
			print 'Sub array with sum is between: ' + str(0) + ' and ' + str(i)
			return
		sum_diff = curr_sum - target_sum
		val = sum_dict.get(sum_diff)
		if val:
			print 'Sub array with sum is between: ' + str(sum_dict[sum_diff]+1) + ' and ' + str(i)
			return
		sum_dict[curr_sum] = i


def test():
	sub_arr_with_sum([1, 4, 20, 3, 10, 5], 6, 33)
