class Solution:
    def longestOnes(self, nums, k: int) -> int:
        maxLength = 0
        numZeros = 0
        l = 0

        for r in range(len(nums)):
            if nums[r] == 0:
                numZeros += 1

            while numZeros > k:
                if nums[l] == 0:
                    numZeros -= 1
                l += 1
            
            currLength = r-l+1
            maxLength = max(maxLength, currLength)

        return maxLength

        


def main():
    self = Solution
    nums = [1,1,1,0,0,0,1,1,1,1,0] 
    k = 2
    nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
    k = 3
    Solution.longestOnes(self, nums, k)
main()