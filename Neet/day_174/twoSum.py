class Solution(object):
    def twoSum(self, nums, target):
        if not nums:
            return []

        n = len(nums)
        val_to_idx = {}
        for i in range(n):
            diff = target-nums[i]
            if diff in val_to_idx:
                return [i, val_to_idx[diff]]
            else:
                val_to_idx[nums[i]] = i
        return [-1, -1]