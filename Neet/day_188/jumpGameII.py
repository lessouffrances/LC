class Solution(object):
    def jump(self, nums):
        if not nums:
            return 0

        dp = [ 0 for _ in range(len(nums)) ]

        for i in range(len(nums)-2, -1, -1):
            if nums[i] == 0:
                dp[i] = float('inf')
            else:
                dp[i] = 1 + min(dp[ i+1 : i+1+nums[i]] )
        return dp[0]