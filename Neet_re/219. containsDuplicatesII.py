class Solution:
    def containsNearbyDuplicate(self, nums, k) -> bool:
        windowSet = set()
        l, r = 0, 0

        while r < len(nums):
            if r-l > k:
                windowSet.remove(nums[l])
                l += 1
            if nums[r] in windowSet:
                return True
            windowSet.add(nums[r])
            r += 1

        return False
        
def main():
    self = Solution
    nums = [1,2,3,1,2,3]
    k = 2
    print(Solution.containsNearbyDuplicate(self, nums, k))
main()