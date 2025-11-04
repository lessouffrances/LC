class Solution:
    def canJump(self, nums) -> bool:
        dp = [ True for _ in range(len(nums)) ]

        for i in range(len(nums)-2, -1, -1):
            print(i)
            if True in dp[ i+1 : i+nums[i]+1 ]:
                dp[i] = True
            else:
                dp[i] = False
        
        print(dp)
        return dp[0]

def main():
    solution = Solution()
    nums = [2,3,1,1,4] #true
    nums = [3,2,1,0,4] #false
    solution.canJump(nums)
main()

