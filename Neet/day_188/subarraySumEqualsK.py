class Solution(object):
    def subarraySum(self, nums, k):

        if not nums:
            return 0

        # build the prefixSum array
        n = len(nums)
        sum_to_count = {}
        sum_to_count[0] = 1

        res = 0
        curr_sum = 0
        for i in range(n):
            curr_sum += nums[i]
            diff = curr_sum - k
            if diff in sum_to_count:
                res += sum_to_count[diff]
            sum_to_count[curr_sum] = sum_to_count.get(curr_sum, 0)+1
        return res

        