"""
Coin denomination problem - Topdown Memoization Approach (Dynamic Programming)
Example: Given the coins with denomination [1,2,3]. Assume that there are infinite number of coins. Find the minimum number of coins to get the value 'x'.
"""

# maxint returns maximum integer value supported python 2.7
from sys import maxint


def coin_denom(coins,dictionary,remain):

    if remain == 0:
        return 0
    elif remain < 0:
        return -1

    if remain in dictionary:
        return dictionary[remain]

    # In Python 2.7, maximum integer value is 2147483647
    min_val = maxint

    for i in coins:
        temp = 1 + coin_denom(coins,dictionary,remain-i)
        if temp < min_val and temp != 0:
            min_val = temp

    if remain not in dictionary:
        dictionary[remain] = min_val

    return min_val

                                ### Testcases ###
#print coin_denom([1,2,3,4], {}, 7)
