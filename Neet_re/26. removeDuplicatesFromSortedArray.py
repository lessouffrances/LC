class Solution:
    def removeDuplicates(self, nums) -> int:
        l, r = 0, 1

        while r<len(nums):
            if nums[r] != nums[r-1]:
                l += 1
                nums[l] = nums[r]
            r += 1

        return l+1

        





def main():
    self = Solution
    nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    Solution.removeDuplicates(self, nums)
main()

