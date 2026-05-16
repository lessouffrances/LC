class Solution(object):
    def longestConsecutive(self, nums):
        if not nums:
            return 0

        nums_set = set(nums)
        max_len = 0
        length = 0

        for num in nums_set:
            if num-1 not in nums_set:
                length = 1
                while num+1 in nums_set:
                    length += 1
                    num = num+1
                max_len = max(max_len, length)
        return max_len