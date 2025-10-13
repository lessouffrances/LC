class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        l, r = 0, k 
        # maxAvg = nums[0]
        nums_0 = nums + [0]
        lst = []
        
        maxi = sum(nums[l:r])
        while r < len(nums_0):
            curr = sum(nums[l:r]) 
            maxi = max(maxi, curr)
            l, r = l + 1, r + 1
        res = maxi / k
        print(res)
        return res
        

            
    
def main():
    self = Solution()
    # nums = [-1]
    nums = [1,12,-5,-6,50,3]
    #         l              r
    k = 4
    # output = 12.75
    Solution.findMaxAverage(self, nums, k)
main()
        