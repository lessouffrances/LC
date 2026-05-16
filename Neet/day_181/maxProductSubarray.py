class Solution(object):
    def maxProduct(self, nums):
        if not nums:
            return 0

        n = len(nums)
        curr_min = nums[0]
        curr_max = nums[0]
        res = nums[0]

        for i in range(1, n):
            temp = curr_max
            curr_max = max( [ nums[i], temp*nums[i], curr_min*nums[i] ] )
            curr_min = min( [ nums[i], temp*nums[i], curr_min*nums[i] ] )
            res = max(res, curr_max)

        return res
        