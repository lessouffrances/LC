class Solution:
    def findTargetSumWays(self, nums, target):
        dp = {}

        def findWays(i, total):
            if i == len(nums):
                return 1 if target == total else 0
            if (i, total) in dp:
                return dp[(i, total)]
            dp[(i, total)] = findWays(i+1, total+nums[i]) + findWays(i+1, total-nums[i])
            return dp[(i, total)]

        return findWays(0, 0)

def main():
    solution = Solution()
    nums = [1, 1, 1, 1, 1]
    target = 3
    print(solution.findTargetSumWays(nums, target))
main()