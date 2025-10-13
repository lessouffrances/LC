class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        maxSub = nums[0]
        currentSum = 0

        for num in nums:
            if currentSum < 0:
                currentSum = 0
            currentSum += num
            maxSub = max(maxSub, currentSum)
        print(maxSub)
        return maxSub


def main():
    self = Solution()
    # nums = [-2, 1, -3, 4,- 1, 2, 1, -5, 4]
    nums = [-1, 0, -1, 0, -1, 0, 2]
    Solution.maxSubArray(self, nums)

main()