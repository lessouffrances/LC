class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return -1

        n = len(nums)
        left, right = 0, n-1
        while left < right:
            mid = (left + right) // 2
            # if the mid was not at the begining of one pair
            if mid % 2 != 0:
                mid -= 1
            
            if mid+1 < n and nums[mid] == nums[mid+1]:
                left = mid+2
            else:
                right = mid

        return nums[left]
            