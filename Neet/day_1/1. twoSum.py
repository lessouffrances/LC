class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        '''for i in range(len(nums)):
            for j in range(len(nums)):
                if (nums[i] + nums[j] == target) and (i != j):
                    lst = [i, j]
        print(sorted(lst))
        return sorted(lst)'''

        prevMap = {}  # val : index -> store the elements visited 

        for i, num in enumerate(nums):
            diff = target - num
            if diff in prevMap:
                
                return [prevMap[diff], i] 
            prevMap[num] = i
        return 
                       


def main():
    self = Solution()
    # nums = list
    # nums = [2, 7, 11, 15]
    nums = [2, 1, 5, 3]
    target = 4
    
    print(Solution.twoSum(self, nums, target))



main()