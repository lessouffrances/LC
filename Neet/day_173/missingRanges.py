class Solution(object):
    def findMissingRanges(self, nums, lower, upper):
        if not nums:
            return [ [lower, upper] ]

        n = len(nums)
        res = []
        # before the lower
        if lower < nums[0]:
            res.append( [lower, nums[0]-1] )

        for i in range(n-1):
            if nums[i+1]-nums[i] != 1:
                res.append( [nums[i]+1, nums[i+1]-1] )

        # before the lower
        if nums[n-1] < upper:
            res.append( [nums[n-1]+1, upper] )

        return res