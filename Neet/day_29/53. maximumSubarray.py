class Solution:
    def maxSubArray(self, nums):
        if not nums:
            return 0
        elif len(nums) == 1:
            return nums[0]
        
        dp = [ 0 for _ in range(len(nums)+1) ]
        dp[1] = nums[0]
        print("Allocated DP: ", dp)
        left = 0

        def findPreviousCompatible(n, l):
            start = n-1
            res = nums[n-1]
            boundary = l

            while start >= boundary:
                currSum = sum(nums[start : n])
                print(f"The current sum ends with {nums[n-1]} is: ", currSum)
                # res = max(sum(nums[start : n]), res)
                if currSum >= res:
                    res = currSum
                    l = start

                start -= 1
            return res, l
            
        for i in range(2, len(dp)):
            # dp[i] = max(dp[i-1], findPreviousCompatible(i))
            if findPreviousCompatible(i, left)[0] > dp[i-1]:
                dp[i] = findPreviousCompatible(i, left)[0]
                left = findPreviousCompatible(i, left)[1]
            else:
                dp[i] = dp[i-1]
            print("The current dp looks like: ", dp, end="\n\n")

        return dp[-1]
        

def main():
    solution = Solution()
    nums = [-2,1,-3,4,-1,2,1,-5,4] # output 6
    # nums = [1] #1
    # nums = [5,4,-1,7,8] #23
    # nums = [-2,-1] #-1
    print(solution.maxSubArray(nums))
main()