class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        count = {}

        for i in range(len(nums)):
            count[nums[i]] = 1 + count.get(nums[i], 0)
        
        for key in count:
            if count[key] == 1:
                print(key)
                return key

def main():
    self = Solution()
    nums = [4,1,2,1,2]
    Solution.singleNumber(self, nums)


main()