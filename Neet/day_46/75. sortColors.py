class Solution:
    def sortColors(self, nums) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        n = len(nums)

        for i in range(1, n):
            curr = nums[i]
            j = i - 1

            while j >= 0 and nums[j] > curr:
                nums[j + 1] = nums[j]
                j -= 1
            nums[j + 1] = curr
            
        return nums









def main():
    solution = Solution()
    nums = [2,0,2,1,1,0] #[0,0,1,1,2,2]
    # nums = [2,0,1] # [0,1,2]
    print(solution.sortColors(nums))
main()