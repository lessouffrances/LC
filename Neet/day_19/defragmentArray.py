class Solution:
    def defrag(self, nums):
        write, read = 0, 0

        while read<len(nums):
            if nums[read] != -1:
                nums[write] = nums[read]
                write += 1
                read += 1
            else:
                while read<len(nums) and nums[read] == -1:
                    read += 1
                
                nums[write] = nums[read]
                write += 1
                read += 1
        print(write)

        for i in range(write, len(nums)):
            nums[i] = -1

        print(nums)
        






def main():
    self = Solution
    nums = [4, 2, 5, -1, 8, -1, -1, 3, 4, -1, 8, 2]
    Solution.defrag(self, nums)
main()