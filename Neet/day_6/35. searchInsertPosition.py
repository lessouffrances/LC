class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        hashSet = set(nums)
        if target in hashSet:
            return nums.index(target)
        
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if target < nums[mid]:
                r = mid - 1
            elif target > nums[mid]:
                l = mid + 1
        return l 


def main():
    self = Solution()
    nums = [1,3,5,6]
    target = 7


    print(Solution.searchInsert(self, nums, target))
main()