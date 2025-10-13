class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = (l + r) // 2

            if target > nums[mid]:
                l = mid + 1
            elif target < nums[mid]:
                r = mid - 1
            else:
                return mid
        return l


def main():
    self = Solution()
    nums = [1, 3, 5, 6]
    target = 5
    print(Solution.searchInsert(self, nums, target))
main()

# This is a binary search algorithm 
# O(logn): binary search 