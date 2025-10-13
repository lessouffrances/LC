class Solution:
    def search(self, nums, target):
        l, r = 0, len(nums)-1

        while l<=r:
            mid = (l+r)//2

            if nums[mid] > target:
                r = mid-1
            elif nums[mid] < target:
                l = mid+1
            else:
                return mid
        return -1
            


        



def main():
    self = Solution
    nums = [-1,0,3,5,9,12]
    target = 9
    Solution.search(self, nums, target)
main()