# Question 1 — Divisible Triplets
# Given an integer array nums and an integer divisor, 
# find the total number of triplets (nums[i], nums[j], nums[k]) 
# where i < j < k such that (nums[i] + nums[j] + nums[k]) is divisible by divisor.

# Function Description:
# int countTriplets(int[] nums, int divisor)
# Returns: int — the total number of valid triplets.
# Example:
# nums = [1, 2, 3, 4, 5], divisor = 3
# Output: 4

# Constraints:
# 3 <= n <= 10^3
# 1 <= nums[i] <= 10^9
# 2 <= divisor <= 10^6

class Solution(object):
    def countTriplets(self, nums, divisor):
        if not nums:
            return 0

        count = 0
        n = len(nums)
        for i in range(n-2):
            for j in range(i+1, n-1):
                for k in range(j+1, n):
                    if (nums[i]+nums[j]+nums[k]) % divisor == 0:
                        count += 1
        return count