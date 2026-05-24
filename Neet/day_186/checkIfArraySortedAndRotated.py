class Solution(object):
    def check(self, nums):
        if not nums:
            return False
        
        n = len(nums)
        drops = 0
        for i in range(n):
            if nums[ (i+1) % n ] < nums[i]: drops += 1
            if drops > 1: return False
        return True
        