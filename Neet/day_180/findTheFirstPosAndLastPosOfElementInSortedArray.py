class Solution(object):
    def searchRange(self, nums, target):
        if not nums:
            return [-1, -1]
        
        first_pos = self.searchRangeHelper(nums, target, True)
        if first_pos == -1:
            return [-1, -1]
        second_pos = self.searchRangeHelper(nums, target, False)
        return [first_pos, second_pos]
        
    def searchRangeHelper(self, nums, target, isFromLeft):
        if not nums:
            return -1
        left = 0
        right = len(nums)-1
        bound = -1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                bound = mid

                if isFromLeft:
                    right = mid-1
                else:
                    left = mid+1
            elif nums[mid] > target:
                right = mid-1
            else:
                left = mid+1
        return bound