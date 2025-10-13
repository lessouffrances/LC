class Solution:
    def containsNearbyDuplicate(self, nums, k):
        left, right = 0, 1
        windowSet = set()
        windowSet.add(nums[left])

        while right < len(nums):
            if right-left > k:
                windowSet.remove(nums[left])
                left += 1

            if right-left <= k and nums[right] not in windowSet:
                windowSet.add(nums[right])
                right += 1
            elif right-left <= k and nums[right] in windowSet:
                return True
        return False
            
def main():
    solution = Solution()
    test_1 = [1, 2, 3, 1]
    k_1 = 3 

    test_2 = [99, 99]
    k_2 = 2

    test_3 = [1, 2, 3, 1, 2, 3]
    k_3 = 2
    print(solution.containsNearbyDuplicate(test_3, k_3))
    
main()