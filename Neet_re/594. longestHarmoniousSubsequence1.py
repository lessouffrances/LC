from collections import defaultdict

class Solution:
    def findLHS(self, nums) -> int:
        counter = defaultdict(int)
        numSet = set(nums)

        for num in nums:
            counter[(num-1, num)] += 1
            counter[(num, num+1)] += 1
        print(counter)
        
        count = 0
        for key, value in counter.items():
            print((key, value))
            if key[0] in numSet and key[1] in numSet:
                count = max(count, value)
        print(count)
        return count




def main():
    self = Solution
    nums = [1,3,2,2,5,2,3,7]
    # nums = [1,2,3,4]
    # nums = [1,1,1,1]
    Solution.findLHS(self, nums)
main()
