class Solution:
    def longestSubarray(self, nums) -> int:
        l, r = 0, 1

        while r < len(nums)-1:
            while nums[l: r+1].count(0) == 1:
                r += 1
            



        
def main():
    self = Solution
    nums = [1,1,0,1]
    nums = [0,1,1,1,0,1,1,0,1]
    nums = [1,1,1]
    print(Solution.longestSubarray(self, nums))
main()