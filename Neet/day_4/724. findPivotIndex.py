
class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        total = sum(nums)

        leftSum = 0
        for i in range(len(nums)):
            rightSum = total - nums[i] - leftSum
            if leftSum == rightSum:
                return i
            leftSum += nums[i]
        return -1

def main():
    self = Solution()
    nums = [1,7,3,6,5,6] # output = 3
    print(Solution.pivotIndex(self, nums))

main()