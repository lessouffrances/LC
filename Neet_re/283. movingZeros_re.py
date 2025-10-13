class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        for i in range(len(nums)):
            if nums[i] == 0:
                nums.append(0)
                nums.remove(nums[i])
        print(nums)

def main():
    self = Solution()
    # nums = [0,1,0,3,12]
    nums = [0, 1]
    Solution.moveZeroes(self, nums)
main()