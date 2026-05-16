class Solution(object):
    def minOperations(self, nums):
        if not nums:
            return 0
        
        n = len(nums)
        res = 0
        for i in range(n-2, -1, -1):
            if nums[i+1] < nums[i]:
                res += (nums[i]-nums[i+1])
        return res