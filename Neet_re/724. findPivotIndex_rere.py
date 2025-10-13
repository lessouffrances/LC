class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        leftSum = 0
        total = sum(nums)

        for i in range(len(nums)):
            rightSum = total - leftSum - nums[i]
            if leftSum == rightSum:
                return i
            leftSum += nums[i]
        return -1

def main():
    self = Solution()
    # nums = [1,7,3,6,5,6]
    # nums = [1, 2, 3]
    nums = [2, 1, -1]
    
    # output = 
    print(Solution.pivotIndex(self, nums))
main()