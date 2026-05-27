class Solution(object):
    def subarraySum(self, nums, k):
        if not nums:
            return 0

        n = len(nums)
        prefix_sum = {}
        prefix_sum[0] = 1

        curr_sum = 0
        count = 0
        for i in range(n):
            curr_sum += nums[i]
            diff = curr_sum - k
            if diff in prefix_sum:
                count += prefix_sum[diff]
            prefix_sum[curr_sum] = prefix_sum.get(curr_sum, 0)+1
        return count

