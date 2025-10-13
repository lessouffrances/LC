class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        l = 1 
        for r in range(1, len(nums)):
            if nums[r] != nums[r - 1]:
                nums[l] = nums[r]
                l += 1
        return l 
    
        
def main():
    self = Solution()
    nums = [0,0,1,1,1,2,2,3,3,4]
    # nums = [0, 1, 2, 3, 4]
    Solution.removeDuplicates(self, nums)
main()