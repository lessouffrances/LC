class Solution:
    def containsNearbyDuplicate(self, nums, k: int) -> bool:
        thisWindow = set()
        l = 0

        for r in range(len(nums)):
            if r - l > k:
                thisWindow.remove(nums[l])
                l += 1
            
            if nums[r] in thisWindow:
                return True
            
            thisWindow.add(nums[r])

        return False





def main():
    self = Solution()
    nums = [1, 2, 3, 4, 5, 6, 7]
    k = 3
    print(Solution.containsNearbyDuplicate(self, nums, k))

main()