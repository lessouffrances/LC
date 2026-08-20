class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        candidate = nums[0]
        count = 1

        for i in range(1, len(nums)):
            count += 1 if nums[i] == candidate else -1
            if count == 0:
                candidate = nums[i]
                count = 1
        return candidate