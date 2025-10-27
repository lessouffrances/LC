from collections import deque
class Solution:
    def containsNearbyDuplicate(self, nums, k) -> bool:
        l, r = 0, 0
        seen = deque()

        while r < len(nums):
            # when r is within the k window
            while r < len(nums) and (r-l) <= k:
                # if r-index in seen
                seen_set = set(seen)
                if nums[r] in seen_set:
                    return True
                # if r not seen 
                else:
                    seen.append(nums[r])
                r += 1
            
            l += 1
            seen.popleft()
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
        