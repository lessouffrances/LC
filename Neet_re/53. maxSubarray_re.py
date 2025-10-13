class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        maxSub = nums[0]
        curr = 0 
        for i in range(len(nums)):
            if curr < 0:
                curr = 0
            curr += nums[i]
            maxSub = max(curr, maxSub)
        return maxSub
        
def main():
    self = Solution()
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    print(Solution.maxSubArray(self, nums))
main()