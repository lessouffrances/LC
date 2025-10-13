class Solution:
    def maxArea(self, height) -> int:
        left, right = 0, len(height)-1
        maxArea = 0

        while left < right:
            area = (right-left) * min(height[left], height[right])
            maxArea = max(area, maxArea)
            
            if height[left] < height[right]:
                left += 1
            else:  
                right -= 1
                
        print(maxArea)
        return maxArea


def main():
    solution = Solution()
    height = [1,8,6,2,5,4,8,3,7] #49
    # height = [1, 1]
    solution.maxArea(height)
main()
