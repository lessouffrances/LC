class Solution:
    def findTargetSumWays(self, nums, target: int) -> int:
        dp = {}

        def divide(i, curr_sum):
            # if the index rolls out of length
            if i == len(nums):
                return 1 if curr_sum == target else 0
            
            # if result cached
            if (i, curr_sum) in dp:
                return dp[(i, curr_sum)]
            
            # calculate the result recursively
            dp[(i, curr_sum)] = divide(i+1, curr_sum+nums[i]) + divide(i+1, curr_sum-nums[i])
            return dp[(i, curr_sum)]
        
        # divide(0, 0) => divide(1, 1) => divide(2, 2)
                                    #  => divide(2, 1) 

                    #  => divide(1,-1) => divide(2, 0)
                                       # => divide(2, -2) 
            
def main():
    solution = Solution()
    nums = [1,1,1,1,1]
    target = 3 #5

    # nums = [1]
    # target = 1 #1
    print(solution.findTargetSumWays(nums, target))
main()