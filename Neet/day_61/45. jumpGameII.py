class Solution:
    def jump(self, nums) -> int:
        dp = [ 0 for _ in range(len(nums)) ]
        
        for i in range(len(nums)-1, -1, -1):
            if i == len(nums)-1:
                continue
            elif nums[i] == 0:
                dp[i] = 2*len(nums)
            else:
                dp[i] = 1+min(dp[ i+1: i+nums[i]+1 ])

        print(dp)

def main():
    solution = Solution()
    nums = [2,3,1,1,4] #2
    nums = [2,3,0,1,4] #2

    solution.jump(nums)
main()