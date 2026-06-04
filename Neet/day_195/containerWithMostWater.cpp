


// height = [1,8,6,2,5,4,8,3,7]
class Solution 
{
    public:
    int maxArea(vector<int>& height) 
    {
        if (height.empty()) return 0;
        int n = height.size();

        int left = 0;
        int right = n-1;

        int maxWater = INT_MIN;
        int currWater = 0;
        while (left < right) {
            currWater = (right-left) * min(height[right], height[left]);
            maxWater = max(maxWater, currWater);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};