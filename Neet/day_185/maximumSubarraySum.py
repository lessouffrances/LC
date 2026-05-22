# T: O(N)
# S: O(1)

class Solution(object):
    def maxProduct(self, nums):
        if not nums:
            return 0
        
        curr_min = nums[0]
        curr_max = nums[0]
        res = nums[0]
        n = len(nums)

        for i in range(1, n):
            temp_max = curr_max
            curr_max = max(nums[i], temp_max*nums[i], curr_min*nums[i])
            curr_min = min(nums[i], temp_max*nums[i], curr_min*nums[i])
            res = max(curr_max, res)
        return res


