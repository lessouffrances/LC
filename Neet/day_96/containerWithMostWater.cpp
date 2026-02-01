class Solution 
{
    public:
    int maxArea(vector<int>& height) 
    {
        if (height.empty()) return 0;
        int n = height.size();
        int maxArea = 0;

        int left = 0, right = n-1;
        while (left < right) {
            int side = min(height[left], height[right]);
            maxArea = max(maxArea, side * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};