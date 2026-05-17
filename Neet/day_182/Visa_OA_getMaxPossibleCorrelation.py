# For 2 arrays a and b of equal length, 
# the array correlation is defined as 
# the sum of all values b[i] where b[i] is greater than a[i].

# Given two integer arrays a and b of the same length, 
# rearrange the elements of array b to maximize the array correlation.
# Return the maximum possible array correlation value.

# Note: You are not allowed to rearrange the elements in array a.

# Example:
# n = 5,
# a = [1, 2, 3, 4, 5]
# b = [3, 5, 4, 6, 2]
# output = 20
# b can be rearranged to [2, 3, 4, 5, 6].
# Now for each index, the integers in b are greater than those in a.
# The array correlation is 2 + 3 + 4 + 5 + 6 = 20.

# n = 5,
# a = [1, 4, 2, 1, 3] => [1, 1, 2, 3, 4]
# b = [2, 1, 3, 2, 2] => [1, 2, 2, 2, 3]
# output = 7

# Function Description:
# Complete the function getMaxArrayCorrelation with following parameters:
# a[n]: the fixed order array
# b[n]: the array to reorder

# Return:
# long int: the maximum possible array correlation

class Solution(object):
    def getMaxArrayCorrelation(self, a, b):
        if not a or not b:
            return 0

        n = len(a)

        sorted_a = a[:]
        sorted_a.sort()
        b.sort()

        j = 0
        res = 0
        for i in range(n):
            if j<n and b[i] > sorted_a[j]:
                res += b[i] 
                j += 1
        return res
