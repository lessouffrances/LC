class Solution(object):
    def findPeakElement(self, nums):
        if not nums:
            return -1
        
        n = len(nums)
        left = 0
        right = n-1

        while left < right:
            mid = (left + right) // 2
            if nums[mid] < nums[mid+1]:
                left = mid+1
            else:
                right = mid

        return left



        