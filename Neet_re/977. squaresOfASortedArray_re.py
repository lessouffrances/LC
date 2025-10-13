class Solution:
    def sortedSquares(self, nums):
        res = []
        for i in range(len(nums)):
            squareNum = nums[i] * nums[i]
            res.append(squareNum)
        
        res.sort()
        return res

def main():
    self = Solution
    nums = [-4,-1,0,3,10]
    Solution.sortedSquares(self, nums)
main()