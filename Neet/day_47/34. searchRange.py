class Solution:
    def searchRange(self, nums, target):
        if not nums:
            return [-1, -1]

        left, right = 0, len(nums)-1
        first_pos = -1

        while left<=right:
            mid = (left+right)//2
            if nums[mid] == target:
                first_pos = mid
                right = mid-1
            elif nums[mid]<target:
                left = mid+1
            else:
                right = mid-1
        
        if first_pos == -1:
            return [-1, -1]
        
        left, right = 0, len(nums)-1
        last_pos = -1

        while left<=right:
            mid = (left+right)//2
            if nums[mid] == target:
                last_pos = mid
                left = mid+1
            elif nums[mid]<target:
                left = mid+1
            else:
                right = mid-1
        
        return [first_pos, last_pos]



        

def main():
    solution = Solution()
    
    nums = [5,7,7,8,8,10]
    target = 8 #[3, 4]

    nums = [5,7,7,8,8,10]
    target = 6 #[-1, -1]

    nums = []
    target = 0 #[-1, -1]
    print(solution.searchRange(nums, target))
main()