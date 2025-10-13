class Solution:
    def maxProduct(self, nums) -> int:
        dp = [ [0, 0] for _ in range(len(nums)) ]
        dp[0] = [nums[0], nums[0]]
        print(f"The initial dp is {dp}.")
        res = max(nums)

        for i in range(1, len(nums)):
            dp[i][0] = max(nums[i]*dp[i-1][0], nums[i]*dp[i-1][1], nums[i])
            dp[i][1] = min(nums[i]*dp[i-1][0], nums[i]*dp[i-1][1], nums[i])
        dp.sort(key=lambda x:x[0], reverse=True)
        print(dp)
        res = max(res, dp[0][0])
        print(res)



def main():
    solution = Solution()
    # nums = [2,3,-2,4] #6
    # nums = [2, 3, 2, -1, -3, 0, 1, 2] #36
    nums = [-2,0,-1] #0
    # nums = [0, 2] #2
    # nums = [-2,3,-4] #24
    # nums = [2, 3, -2, 4] #6
    # nums = [0, 2] #2
    solution.maxProduct(nums)
main()