class Solution(object):
    def removeElement(self, nums, val):
        if not nums:
            return -1
        
        write = 0
        for read in range(len(nums)):
            if nums[read] != val: 
                nums[write] = nums[read]
                write += 1
        
        return write