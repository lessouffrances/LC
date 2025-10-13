class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        prevMap = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in prevMap and (prevMap[diff] != i):
                return [prevMap[diff], i]
            prevMap[nums[i]] = i
        
                
def main():
    self = Solution()
    nums = [2,7,11,15] # output = [0, 1]
    # prevMap = {3:0, 3:1}
    target = 9
    print(Solution.twoSum(self, nums, target))
main()