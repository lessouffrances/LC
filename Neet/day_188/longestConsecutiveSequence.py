class Solution(object):
    def longestConsecutive(self, nums):
        if not nums:
            return 0
        
        num_set = set(nums)
        curr_len = 1
        max_len = 1
        for num in num_set:
            if (num-1) not in num_set:
                curr_len = 1
                while num+1 in num_set:
                    curr_len += 1
                    num = num+1
                max_len = max(max_len, curr_len)
        return max_len
