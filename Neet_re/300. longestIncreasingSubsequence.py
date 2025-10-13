class Solution:
    def lengthOfLIS(self, nums) -> int:
        LIS = [1] * len(nums)

        for i in range(len(nums)-1, -1, -1):
            for j in range(i+1, len(nums)):
                if nums[j]>nums[i]:
                    LIS[i] = max(LIS[i], 1+LIS[j])
        return max(LIS)
    
    def returnLIS(self, nums):
        


def main():
    self = Solution
    nums = [10,9,2,5,3,7,101,18] # output = 4 [2, 3, 7, 101]
    print(Solution.lengthOfLIS(self, nums))
main()