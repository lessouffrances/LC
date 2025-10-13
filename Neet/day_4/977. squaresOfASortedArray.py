class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        for i in range(len(nums)):
            nums[i] = nums[i] * nums[i]
        nums = sorted(nums)
        print(nums)    
        return nums

def main():
    self = Solution()
    nums = [-4,-1,0,3,10]
    Solution.sortedSquares(self, nums)

main()
