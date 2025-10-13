class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        majorCount = (len(nums) // 2) + 1
        for num in nums:
            if nums.count(num) >= majorCount:
                return num

def main():
    self = Solution()
    # nums = [2,2,1,1,1,2,2]
    nums = [3,2,3]
    print(Solution.majorityElement(self, nums))
main()