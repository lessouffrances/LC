class Solution:
    def longestOnes(self, nums, k: int) -> int:
        maxLength = 0
        currLength = 0
        zeroCount = 0
        l, r = 0, 0

        while r < len(nums):
            if nums[r] == 0:
                zeroCount += 1
            
            while zeroCount > k:
                if nums[l] == 0:
                    zeroCount -= 1
                l += 1
            
            currLength = r-l+1
            maxLength = max(maxLength, currLength)
            r += 1
            
        return maxLength





def main():
    self = Solution
    # nums = [1,1,1,0,0,0,1,1,1,1,0]
    # k = 2

    nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
    k = 3
    print(Solution.longestOnes(self, nums, k))
main()