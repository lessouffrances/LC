class Solution 
{
    public:
    int maxArea(vector<int>& height) 
    {
        if (height.empty()) return 0;

        int n = height.size();
        int left = 0, right = n-1;
        int maxWater = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            maxWater = max(maxWater, h * (right-left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};