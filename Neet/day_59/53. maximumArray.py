class Solution:
    def maxSubArray(self, nums) -> int:
        l, r = 0, 0
        max_sum = nums[0]
        dp = [0 for _ in range(len(nums))]
        curr_array_sum = nums[0]

        while r < len(nums):
            if r > l:
                curr_array_sum += nums[r]

            if nums[r] > curr_array_sum:
                l = r
                curr_array_sum = nums[r]

            max_sum = max(max_sum, curr_array_sum)
            dp[r] = max_sum
            r += 1
        
        return max(dp)


def main():
    solution = Solution()
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4] #6
        # 0 -2  1   1  4   4  5  6   6  6   
    # nums = [1] #1
    # nums = [5,4,-1,7,8] #23
    # nums = [8,-19,5,-4,20] #21
         #  8  8  8  8 21
    solution.maxSubArray(nums) 
main()
        
        