class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 0: return []
        n = len(nums)
        # all the numbers we need to take into consideration are 0,1,2
        counter = [0] * 3
        for i in range(n):
            counter[nums[i]] += 1
        
        j = 0
        for i in range(3):
            while counter[i] > 0:
                nums[j] = i
                j += 1
                counter[i] -= 1
        
        return nums