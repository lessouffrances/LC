class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        hashSet = set(nums)
        return len(nums) > len(hashSet)

def main():
    self = Solution()
    # nums = [1,1,1,3,3,4,3,2,4,2]
    nums = [1, 2, 3, 4]
    print(Solution.containsDuplicate(self, nums))
main()