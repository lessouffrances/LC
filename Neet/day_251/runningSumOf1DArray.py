class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) == 0: return []

        currSum = 0
        res = []
        for i in range(len(nums)):
            currSum += nums[i]
            res.append(currSum)
        return res
