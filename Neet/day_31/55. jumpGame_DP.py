class Solution:
    def canJump(self, nums) -> bool:
        if not nums:
            return False
        
        if len(nums) == 1:
            return True
        
        dp = [ 0 for _ in range(len(nums)) ]
        dp[-1] = True
        previousCanJumpIndex = len(dp)-1

        for i in range(len(nums)-2, -1, -1):
            print(f"Filling the {i}-th position in dp.")
            if nums[i] >= len(nums)-1-i:
                dp[i] = True
                previousCanJumpIndex = i
            elif nums[i] >= previousCanJumpIndex-i:
                dp[i] = True
                previousCanJumpIndex = i
            else:
                dp[i] = False
            print("The current dp looks like: ", dp)

        return dp[0]

def main():
    solution = Solution()
    nums = [2,3,1,1,4] #true
    # nums = [3,2,1,0,4] #false
    print(solution.canJump(nums))
main()