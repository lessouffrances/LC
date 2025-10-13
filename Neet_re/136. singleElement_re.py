class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        for num in nums:
            if nums.count(num) == 1:
                return num
        
def main():
    self = Solution()
    nums = [4,1,2,1,2]
    Solution.singleNumber(self, nums)


main()