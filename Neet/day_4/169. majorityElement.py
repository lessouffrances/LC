class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        majority_count = len(nums) / 2 
        nums = [0] + sorted(nums) 
        count = 1

        for i in range(1, len(nums)):
            if nums[i - 1] == nums[i]:
                count += 1
                if count >= majority_count:
                    return nums[i]
        

    
def main():
    self = Solution()
    # nums = [2,2,1,1,1,2,2]
    nums = [3,2,3]
    print(Solution.majorityElement(self, nums))

main()



        