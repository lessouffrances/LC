class Solution:
    def removeDuplicates(self, nums) -> int:
        # my approach, it presents the array but no k is tracked
        # if not nums:
        #     return 0
        
        # for i in range(1, len(nums)-1):
        #     if nums[i-1] == nums[i] and nums[i+1] == nums[i]:
        #         nums[i: -1] = nums[i+1:]
        #     print(nums)
        
        # for i in range(1, len(nums)):
        #     if nums[i-1] == nums[i]:
        #         print(i)
        #         return i
        
        # correct approach with k being tracked:
        
        # l, r = 0, 0 

        # while r < len(nums):
        #     count = 1
        #     while r+1 < len(nums) and nums[r] == nums[r+1]:
        #         r += 1
        #         count += 1
            
        #     for i in range(min(2, count)):
        #         nums[l] = nums[r]
        #         l += 1
        #     r +=1 

        # print(nums[:l])
        # return l
         
        # If the definition of removing duplicates is unique numbers in a row:
        l, r = 0, 0
        
        while r < len(nums):
            
            while r+1 < len(nums) and nums[r] == nums[r+1]:
                r += 1
            
            nums[l] = nums[r]
            l += 1
            r += 1
        
        print(nums[: l])
        return l

def main():
    self = Solution()
    nums = [1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5]
    # nums =  [1, 1, 1, 2, 2, 3]
    print(Solution.removeDuplicates(self, nums))
main()