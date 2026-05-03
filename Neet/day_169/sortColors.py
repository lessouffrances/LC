class Solution(object):
    def sortColors(self, nums):
        if not nums:
            return nums

        for i in range(1, len(nums)):
            key = nums[i]
            j = i-1
            while j>=0 and nums[j]>key:
                nums[j+1] = nums[j]
                j -= 1
            nums[j+1] = key