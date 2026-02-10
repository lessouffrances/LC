







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
            int water = (right-left) * min(height[right], height[left]);
            maxWater = max(maxWater, water);

            if (height[right] <= height[left]) {
                right--;
            } else {
                left++;
            }
        }
        return maxWater;
    }
};