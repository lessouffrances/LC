class Solution(object):
    def trap(self, height):
        if not height:
            return 0

        n = len(height)

        max_left_num = -float('inf')
        max_left = [0] * n
        for i in range(1, n):
            max_left_num = max(max_left_num, height[i-1])
            max_left[i] = max_left_num
        
        max_right_num = -float('inf')
        max_right = [0] * n
        for i in range(n-2, 0, -1):
            max_right_num = max(max_right_num, height[i+1])
            max_right[i] = max_right_num
        
        water = 0
        for i in range(n):
            min_lr = min(max_left[i], max_right[i])
            if min_lr > height[i]:
                water += (min_lr - height[i])
        return water
    