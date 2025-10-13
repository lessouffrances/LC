class Solution:
    def containsNearbyDuplicate(self, nums, k: int) -> bool:
        windowSet = set()
        
        for r in range(len(nums)):
            if nums[r] in windowSet:
                return True
            else:
                windowSet.add(nums[r])

            if r>=k:
                windowSet.remove(nums[r-k])

        return False

def main():
    self = Solution
    nums = [1,2,3,1]
    k = 3
    nums = [1,0,1,1]
    k = 1
    nums = [1,2,3,1,2,3]
    k = 2
    print(Solution.containsNearbyDuplicate(self, nums, k))
main()