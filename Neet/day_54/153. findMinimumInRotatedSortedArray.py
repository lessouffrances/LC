class Solution:
    def findMin(self, nums) -> int:
        l, r = 0, len(nums)-1
        # if the array is sorted return the first element
        if nums[r] >= nums[l]:
            return nums[l]

        while l < r:
            mid = (l+r)//2
             
            # if the mid is at the edge of the array
            if mid in [l, r]:
                if nums[r] < nums[r-1]:
                    return nums[r]
                elif nums[l] < nums[l+1]:
                    return nums[l]
            # or if the mid is not at the edge of the array
            elif nums[mid] < nums[mid-1] and nums[mid] < nums[mid+1]:
                return nums[mid]

            # if left half is sorted
            elif nums[mid] > nums[l]:
                l = mid

            # if right half is sorted
            elif nums[mid] < nums[l]:
                r = mid
            
            else:
                l = mid+1
            
        
def main():
    solution = Solution()
    nums = [3,4,5,1,2] #1
    nums = [4,5,6,7,0,1,2] #0
    # nums = [11,13,15,17] #11
    print(solution.findMin(nums))
main()