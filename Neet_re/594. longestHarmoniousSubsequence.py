from collections import defaultdict
class Solution:
    def findLHS(self, nums) -> int:
        counter = defaultdict(int)

        for num in nums:
            counter[(num, num+1)] += 1
            counter[(num-1, num)] += 1
        print(counter)

        numSet = set(nums)
        res = 0
        for key, value in counter.items():
            print((key, value))
            if key[0] in numSet and key[1] in numSet:
                res = max(res, value)
        print(res)
        return res

def main():
    self = Solution
    nums = [1,3,2,2,5,2,3,7]
    # nums = [1,2,3,4]
    # nums = [1,1,1,1]
    Solution.findLHS(self, nums)
main()