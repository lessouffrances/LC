class Solution:
    def rob(self, nums: list[int]) -> int:
         money_1 = 0
         i = 0
         while i < len(nums):
              money_1 += nums[i]
              i += 2

         money_2 = 0
         j = 1
         while j < len(nums):
              money_2 += nums[j]
              j += 2
         print(max(money_1, money_2))
         return max(money_1, money_2)

              
def main():
     self = Solution()
     nums = [2, 7, 9, 3, 1]
     Solution.rob(self, nums)

main()
              
              
        