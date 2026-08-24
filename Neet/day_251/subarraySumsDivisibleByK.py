class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if len(nums) == 0: return 0

        remainderCount = {} # a map
        remainderCount[0] = 1

        currSum = 0
        count = 0
        for num in nums:
            currSum += num
            remainder = ((currSum % k) + k) % k
            count += remainderCount.get(remainder, 0)
            remainderCount[remainder] = remainderCount.get(remainder, 0)+1

        return count

            

            

