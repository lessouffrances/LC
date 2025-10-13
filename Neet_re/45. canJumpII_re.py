class Solution:
    def canJump(self, nums):
        res = 0
        l = r = 0
        
        while r < len(nums) - 1:
            farthest = 0
            for i in range(l, r+1):
                farthest = max(farthest, i+nums[i])
        
            l = r + 1
            r = farthest
            res += 1
        return res
        
        
        
def main():
    self = Solution()
    nums = [2,3,1,1,4] 
    print(Solution.canJump(self, nums))
main()