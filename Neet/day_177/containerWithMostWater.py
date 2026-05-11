class Solution(object):
    def maxArea(self, height):
        if not height:
            return 0
        
        curr_water = 0
        max_water = -float('inf')
        left = 0
        right = len(height)-1

        while left < right:
            curr_water = (right-left) * min(height[left], height[right])
            max_water = max(max_water, curr_water)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_water

        