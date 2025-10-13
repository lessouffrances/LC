class Solution:
    def search(self, nums: list[int], target: int) -> int:
        hashSet = set(nums)
        if target not in hashSet:
            return -1
        
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            if target > nums[mid]:
                l = mid + 1
            elif target < nums[mid]:
                r = mid - 1
            elif target == nums[mid]:
                return mid
        return l

def main():
    self = Solution()
    nums = [-1,0,3,5,9,12]
    target = 9
    print(Solution.search(self, nums, target))
main()