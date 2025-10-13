class Solution:
    def lengthOfLIS(self, nums) -> int:
        LIS = [1] * len(nums)

        for i in range(len(nums)-1, -1, -1):
            for j in range(i+1, len(nums)):
                if nums[i] < nums[j]:
                    LIS[i] = max(LIS[i], 1 + LIS[j])
                    
        return max(LIS)


def main():
    self = Solution()
    nums = [10,9,2,5,3,7,101,18]
    print(Solution.insert(self, nums))

main()
        
