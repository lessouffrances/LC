from collections import defaultdict
class Solution:
    def findLHS(self, nums) -> int:
        counter = defaultdict(int)

        for n in nums:
            counter[(n, n+1)] += 1
            counter[(n-1, n)] += 1
        print(counter)
        
        output = 0
        numSet = set(nums)
        for key, value in counter.items():
            print((key, value))
            if key[0] in numSet and key[1] in numSet:
                output = max(output, value)
        return output

def main():
    self = Solution
    nums = [1,3,2,2,5,2,3,7]
    # output = 5, [3,2,2,2,3]

    # nums = [1,2,3,4]
    # output = 2 [1, 2], [2, 3], [3, 4]

    # nums = [1,1,1,1]
    # output = 0
    Solution.findLHS(self, nums)
main()