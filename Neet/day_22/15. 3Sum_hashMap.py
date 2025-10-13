class Solution:
    def threeSum(self, nums):
        nums.sort()
        res = []
        
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            left, right = i+1, len(nums)-1
            
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif total > 0:
                    right -= 1
                else:
                    left += 1
        print(res)            
        return res            
                         
def main():
    solution = Solution()  
    nums = [2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4, 5, 5, -10]
    # expected: [[-10,5,5],[-5,0,5],[-4,2,2],[-3,-2,5],[-3,1,2],[-2,0,2]]
    solution.threeSum(nums)  
main()
