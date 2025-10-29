class Solution:
    def lengthOfLIS(self, nums) -> int:
        # Recurrnece Analysis
        #    [0, 1, 0, 3, 2, 3]
        #    [1, 0, 0, 0, 0, 0]

        # base case: dp[1] = 1, for the first element, the LIS is itself
        # recurrence: dp[i] = 1 + previousCompatible(i)

        dp = [ 0 for _ in range(len(nums)) ]
        dp[0] = 1

        def previousCompatible(n):
            candidates = []
            for i in range(n): 
                if nums[i] < nums[n]:
                    candidates.append(dp[i])
            return max(candidates) if candidates else 0
        
        for i in range(1, len(dp)):
            dp[i] = 1+previousCompatible(i)

        print(dp)
        return max(dp)

def main():
    solution = Solution()
    nums = [10,9,2,5,3,7,101,18] #4
    nums = [0,1,0,3,2,3] #4
    # nums = [7,7,7,7,7,7,7] #1
    solution.lengthOfLIS(nums)
main()
        


        


        