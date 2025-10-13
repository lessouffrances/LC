class Solution:
    def search(self, nums: list[int], target: int) -> int:
        l, r = 0, len(nums) - 1
    
        while l <= r:
            mid = int((l + r) / 2)
            if target < nums[mid]:
                r = mid - 1
            elif target > nums[mid]:
                l = mid + 1
            elif target == nums[mid]:
                return mid
        return - 1
        
def main():
    self = Solution()
    nums = [5]
    target = 5
    print(Solution.search(self, nums, target))

main()
        