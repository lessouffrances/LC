# T1 — Maximum Even Sum Subset
# Problem: Given n integers, select any subset (including empty) 
# such that the sum is even and as large as possible.

# Approach: Compute the sum S of all positive numbers. 
# If S is even, return it directly. 
# If S is odd, we need to make it even by either:
# Subtracting the smallest positive odd number, or
# Adding the largest negative odd number 
# Take whichever gives the larger result.

class Solution(object):
    def getMaxEvenSum(self, nums):
        total_pos_sum = 0
        min_pos_odd = float('inf')
        max_neg_odd = -float('inf')

        for num in nums:
            if num > 0:
                total_pos_sum += num
                if num % 2 != 0:
                    min_pos_odd = min(min_pos_odd, num)
            else:
                if num % 2 != 0:
                    max_neg_odd = max(max_neg_odd, num)
        
        if total_pos_sum % 2 == 0:
            return total_pos_sum
        
        best = 0
        if min_pos_odd != float('inf'):
            best = max(0, total_pos_sum - min_pos_odd)
        if max_neg_odd != -float('inf'):
            best = max(best, total_pos_sum + max_neg_odd)
        return best