class Solution:
    def findMatrix(self, nums):
        res = []
        while nums:
            currRow = []
            for (index, num) in enumerate(nums):
                if num not in set(currRow):
                    currRow.append(num)
                    nums[index] = ""

            nums = [ num for num in nums if num != "" ]
            res.append(currRow)
        
        return res


def main():
    self = Solution
    nums = [1,3,4,1,2,3,1]
    Solution.findMatrix(self, nums)
main()