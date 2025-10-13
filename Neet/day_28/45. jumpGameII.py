class Solution:
    def jump(self, nums) -> int:
        if not nums or len(nums) == 1:
            return 0
        
        dp = [ 0 for i in range(len(nums)+1) ]

        def findPreviousCompatible(n):
            minStep = dp[n+1]
            for i in range(n+1, n+nums[n-1]+1):
                minStep = min(minStep, dp[i])
            return minStep
            
        for i in range(len(nums)-1, 0, -1):
            if nums[i-1] == 0:
                dp[i] = max(nums) * max(nums)
            elif nums[i-1] >= (len(nums)-1)-(i-1):
                dp[i] = 1
            else:
                dp[i] = findPreviousCompatible(i)+1
        return dp[1]
        
                
def main():
    solution = Solution()
    nums = [2,3,1,1,4] #2
    # nums = [2,3,0,1,4] #2
    solution.jump(nums)
main()