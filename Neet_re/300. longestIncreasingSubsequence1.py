class Solution:
    def lengthOfLIS(self, nums) -> int:
        cache = [0] * len(nums)
        cache[-1] = 1

        for i in range(len(nums)-1, -1, -1):
            for j in range(i+1, len(nums)):
                if nums[i]<nums[j]:
                    cache[i] = max(cache[i], 1+cache[j])
        print(cache)
        return max(cache)
        
def main():
    self = Solution
    # nums = [10,9,2,5,3,7,101,18] # output = 4
    # nums = [0,1,0,3,2,3] # output = 4
    # nums = [7,7,7,7,7,7,7] # output = 1
    nums = [4,10,4,3,8,9] # output = 3
    Solution.lengthOfLIS(self, nums)
main()