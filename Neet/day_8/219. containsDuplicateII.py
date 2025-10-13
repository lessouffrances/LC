class Solution:
    def containsNearbyDuplicate(self, nums, k) -> bool:
        window = set()
        L = 0

        for R in range(len(nums)):
            if R - L > k:
                window.remove(nums[L]) # Classic sliding window technique
                L += 1

            if nums[R] in window: # perfect usage of a set()
                return True
            window.add(nums[R])
        return False 

def main():
    self = Solution()
    nums = [1, 2, 3, 1, 2, 3]
    # 
    k = 2
    print(Solution.containsNearbyDuplicate(self, nums, k))
main()