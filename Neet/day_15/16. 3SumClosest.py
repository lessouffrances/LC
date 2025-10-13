class Solution:
    def threeSumClosest(self, nums, target: int) -> int:
        nums.sort()
        res = sum(nums[:3])

        for i in range(len(nums)-2):
            l = i+1
            r = len(nums)-1

            while l < r:
                currSum = nums[i] + nums[r] + nums[l]
                if abs(currSum-target) < abs(res-target):
                    res = currSum
                if currSum < target:
                    l += 1
                else:
                    r -= 1
        return res



def main():
    self = Solution
    nums = [-1,2,1,-4]
    target = 1
    nums = [0,0,0]
    target = 1
    Solution.threeSumClosest(self, nums, target)
main()