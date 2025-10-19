class Solution:
    def search(self, nums, target) -> int:
        left, right = 0, len(nums)-1

        while left <= right:
            mid = (left + right) // 2
            print(f"mid value: {nums[mid]}")
            
            if nums[mid] == target:
                return mid
            
            # left half is sorted
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1

            # right half is sorted
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        
        return -1
    
def main():
    solution = Solution()
    
    nums = [4,5,6,7,0,1,2]
    target = 0 # Expected: 4
    
    nums = [4,5,6,7,0,1,2]
    target = 3 # Expected: -1
    
    nums = [1]
    target = 0 # Expected: -1
    
    solution.search(nums, target)
main()