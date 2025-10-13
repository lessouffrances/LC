class Solution:
    def longestSubarray(self, nums, limit):
        if not nums:
            return 0
        
        left, right = 0, 1
        max_length = 0

        while right <= len(nums):
            curr_subarray = nums[left: right+1]
            if abs(max(curr_subarray)-min(curr_subarray)) <= limit:
                right += 1
                max_length = max(max_length, len(curr_subarray))
            else:
                while left <= len(nums) and abs(max(nums[left: right+1])-min(nums[left: right+1])) > limit:
                    left += 1
                right = left+1
        print(max_length)

        # for right in range(1, len(nums)+1):
        #     curr_subarray = nums[left: right]
        #     print(f"The curr subarray is: {curr_subarray}")

        #     max_diff = abs(max(curr_subarray)-min(curr_subarray))
        #     if max_diff <= limit:
        #         max_length = len(curr_subarray)
        #     else:
        #         left += 1
        # print(max_length)


# Optimized Solution using Monotonic Deques - O(n) time, O(n) space
class SolutionOptimized:
    def longestSubarray(self, nums, limit):
        from collections import deque
        
        if not nums:
            return 0
        
        # Monotonic deques to track max and min in current window
        max_deque = deque()  # Decreasing deque (front has max)
        min_deque = deque()  # Increasing deque (front has min)
        
        left = 0
        max_length = 0
        
        for right in range(len(nums)):
            # Maintain decreasing deque for maximum
            # Remove smaller elements from back since they won't be the max
            while max_deque and nums[max_deque[-1]] <= nums[right]:
                max_deque.pop()
            max_deque.append(right)
            
            # Maintain increasing deque for minimum
            # Remove larger elements from back since they won't be the min
            while min_deque and nums[min_deque[-1]] >= nums[right]:
                min_deque.pop()
            min_deque.append(right)
            
            # Shrink window if difference exceeds limit
            while max_deque and min_deque and nums[max_deque[0]] - nums[min_deque[0]] > limit:
                left += 1
                # Remove indices that are out of window
                if max_deque[0] < left:
                    max_deque.popleft()
                if min_deque[0] < left:
                    min_deque.popleft()
            
            max_length = max(max_length, right - left + 1)
        
        print(max_length)
        return max_length


def main():
    solution = Solution()
    solution_opt = SolutionOptimized()
    
    nums = [8,2,4,7]
    limit = 4 #2

    nums = [10,1,2,4,7,2]
    limit = 5 #4

    nums = [4,2,2,2,4,4,2,2]
    limit = 0 #3

    nums = [1]
    limit = 0 #1

    print("Original solution:")
    solution.longestSubarray(nums, limit)
    
    print("\nOptimized solution:")
    solution_opt.longestSubarray(nums, limit)



main()