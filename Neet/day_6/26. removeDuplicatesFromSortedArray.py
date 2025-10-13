class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        hashSet = set(nums)
        lst = sorted(list(hashSet))
        print(lst)

        for i in range(len(nums)):
            if i < len(lst):
                nums[i] = lst[i]
            else:
                nums[i] = 0
        
        print(nums)
        return len(lst)
    
        # Neet's approch:
        # l = 1 
        # for r in range(1, len(nums)):
        #     if nums[r] != nums[r - 1]:
        #         nums[l] = nums[r]
        #         l += 1
        # return l 

def main():
    self = Solution()
    nums = [-1,0,0,0,0,3,3]
    print(Solution.removeDuplicates(self, nums))

main()

        