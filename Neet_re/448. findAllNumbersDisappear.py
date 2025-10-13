class Solution:
    def findDisappearedNumbers(self, nums):
        numsSet = set(nums)
        n = len(nums)
        res = []
        for i in range(1, n+1):
            if i not in numsSet:
                res.append(i)
        return res



def main():
    self = Solution()
    nums = [4,3,2,7,8,2,3,1]
    print(Solution.findDisappearedNumbers(self, nums))
main()