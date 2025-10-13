class Solution:
    def removeDuplicates(self, nums) -> int:
        if not nums:
            return 0
        
        count = 0
        l = 1
        for r in range(1, len(nums)):
            if nums[r] == nums[r-1]:
                count += 1
            else:
                count = 1
            if count <= 2:
                nums[l] = nums[r]
                l+= 1
        return l


            







def main():
    self = Solution
    nums = [0,0,1,1,1,1,2,3,3]
    # nums = [0,0,1,1,2,3,3,_,_]
    # output = 7
    print(Solution.removeDuplicates(self, nums))
main()