class Solution(object):
    def longestOnes(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if len(nums) == 0: return 0
        left = 0
        max_len = 0

        windowCountOfZeros = 0
        for right in range(len(nums)):
            if nums[right] == 0:
                windowCountOfZeros += 1
            
            # invalid window
            while windowCountOfZeros > k:
                if nums[left] == 0:
                    windowCountOfZeros -= 1
                left += 1
            max_len = max(max_len, right-left+1)
        
        return max_len
            