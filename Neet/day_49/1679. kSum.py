class Solution:
    def maxOperations(self, nums, k):
        nums.sort()
        print(nums)
        res = 0
        left, right = 0, len(nums)-1

        while left < right:
            curr_sum = nums[left]+nums[right]
            print(f"curr sum is {curr_sum}.")
            if curr_sum == k:
                left += 1
                right -= 1
                res += 1
            elif curr_sum > k:
                right -= 1
            elif curr_sum < k:
                left += 1
            else:
                return -1

        
        print(res)
        return res
            

def main():
    solution = Solution()
    nums = [1,2,3,4]
    k = 6 #-1
    # nums = [3,1,3,4,3]
    # k = 6 #1
    solution.maxOperations(nums, k)
main()