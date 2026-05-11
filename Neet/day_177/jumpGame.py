class Solution(object):
    def canJump(self, nums):
        if not nums:
            return False

        n = len(nums)
        max_reach = 0

        for i in range(n):
            if max_reach < i:
                return False
            max_reach = max(max_reach, i+nums[i])
            if max_reach >= n-1:
                return True
                
        return False