class Solution:
    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        hashNums = {}
        for i, num in enumerate(nums):
            hashNums[num] = i
        print(hashNums)
        
        notThere = []
        for i in range(1, len(nums) + 1):
            if i not in hashNums:
                notThere.append(i)
        print(notThere)
        return notThere

def main():
    self = Solution()
    # nums = [4,3,2,7,8,2,3,1] # n = len(nums)
    nums = [1,1] 
    Solution.findDisappearedNumbers(self, nums)


main()
