class Solution:
    def search(self, nums, target) -> bool:
        left, right = 0, len(nums)-1

        while left<=right:
            mid = (left+right)//2
            if nums[mid] == target:
                return True
            
            # Handle duplicates: when we can't determine which half is sorted
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1
            
            # Left half is sorted
            elif nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid-1
                else:
                    left = mid+1

            # Right half is sorted
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid+1
                else:
                    right = mid-1
        return False
            
        
def main():
    solution = Solution()
    nums = [2,5,6,0,0,1,2]
    target = 0 #true

    nums = [2,5,6,0,0,1,2]
    target = 3 #false
    
    nums = [1,0,1,1,1]
    target = 0 #true

    print(solution.search(nums, target))


main()
        