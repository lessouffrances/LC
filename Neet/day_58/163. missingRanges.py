class Solution:
    def findMissingRanges(self, nums, lower: int, upper: int):
        if len(nums) == 0:
            return [[lower, upper]]
        res = []
        if nums[0] > lower:
                res.append([lower, nums[0]-1])
        for i in range(len(nums)):
            if i+1<len(nums) and nums[i+1]-nums[i] != 1:
                res.append([nums[i]+1, nums[i+1]-1])
        
        if nums[-1] < upper:
                res.append([nums[-1]+1, upper])
        
        print(res)
        return res
        

def main():
    solution = Solution()
    nums = [0,1,3,50,75]
    lower = 0
    upper = 99 # [[2,2],[4,49],[51,74],[76,99]]

    nums = [-1]
    lower = -1
    upper = -1 #[]
    solution.findMissingRanges(nums, lower, upper)
main()