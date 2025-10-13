class Solution:
    def findMaxAverage(self, nums, k):
        i = 0
        curr = sum(nums[i: i+k])
        maxi = curr
        for i in range(k, len(nums)):
            curr += nums[i] - nums[i-k]
            maxi = max(curr, maxi)
        return maxi/k





def main():
    self = Solution
    nums = [1,12,-5,-6,50,3]
    k = 4
    # nums = [5]
    # k = 1
    print(Solution.findMaxAverage(self, nums, k))

main()