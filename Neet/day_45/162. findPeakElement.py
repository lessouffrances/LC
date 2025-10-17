class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
            
        left, right = 0, len(nums)-1
        def binarySearch(l, r):
            while l < r:
                mid = (l+r)//2

                if mid-1 >=0 and mid+1 < len(nums) and max(nums[mid], nums[mid-1], nums[mid+1]) == nums[mid]:
                    return mid
                elif mid-1 < 0 and nums[mid] > nums[mid+1]:
                    return mid
                elif mid+1 > len(nums)-1 and nums[mid] > nums[mid-1]:
                    return mid
                else:
                    if nums[mid] < nums[mid+1]:
                        temp_l = mid+1
                        return binarySearch(temp_l, r)
                    else:
                        temp_r = mid-1
                        return binarySearch(l, temp_r)
            return l
        return binarySearch(left, right)

            
def main():
    solution = Solution()
    nums = [1,2,3,1]
    nums = [1,2,1,3,5,6,4]
    nums = [1,2] #1
    print(solution.findPeakElement(nums))
main()