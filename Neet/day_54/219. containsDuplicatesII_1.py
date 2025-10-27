class Solution:
    def containsNearbyDuplicate(self, nums, k) -> bool:
        l, r = 0, 0
        seen = set()

        while r < len(nums):
            while r < len(nums) and (r-l) <= k:
                if nums[r] in seen:
                    return True
                else: 
                    seen.add(nums[r])
                r += 1
            seen.remove(nums[l])
            l += 1

        return False
    
                
def main():
    solution = Solution()
    nums = [1,2,3,1]
    k = 3 #true

    # nums = [1,0,1,1]
    # k = 1 # true

    nums = [1,2,3,1,2,3]
    k = 2 # false
    print(solution.containsNearbyDuplicate(nums, k))
main()
        