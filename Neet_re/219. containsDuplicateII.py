class Solution:
    def containsNearbyDuplicate(self, nums, k: int) -> bool:
        windowSet = set()

        for r in range(len(nums)):
            if r > k:
                windowSet.remove(nums[r-k-1])
            if nums[r] in windowSet:
                return True
            windowSet.add(nums[r])
        
        return False

            
                


        


def main():
    self = Solution
    nums = [1,2,3,1]
    k = 3
    # nums = [1,0,1,1]
    # k = 1
    # nums = [1,2,3,1,2,3]
    # k = 2
    
    print(Solution.containsNearbyDuplicate(self, nums, k))
main()