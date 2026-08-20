class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        if len(height) == 0: return 0
        n = len(height)

        left, right = 0, n-1
        max_water = 0
        while left < right:
            max_water = max(max_water, (right-left) * min(height[left], height[right]))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_water
