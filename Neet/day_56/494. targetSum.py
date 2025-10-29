class Solution:
    def findTargetSumWays(self, nums, target: int) -> int:
        def divide(i, curr_sum):
            if i == len(nums):
                return 1 if curr_sum == target else 0 

            add_branch = divide(i+1, curr_sum+nums[i])
            subtract_branch = divide(i+1, curr_sum-nums[i])

            return add_branch + subtract_branch
        
        return divide(0, 0)            
        
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