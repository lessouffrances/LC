class Solution 
{
    public:
    int trap(vector<int>& height) 
    {
        if (height.empty()) return 0;
        int n = height.size();

        // construct maxLeft array
        int maxLeft = INT_MIN;
        vector<int> maxLeftNums(n, 0);
        for (int i=1; i<n; i++) {
            maxLeft = max(maxLeft, height[i-1]);
            maxLeftNums[i] = maxLeft;
        }

        // construct maxRight array
        int maxRight = INT_MIN;
        vector<int> maxRightNums(n, 0);
        for (int i=n-2; i>=0; i--) {
            maxRight = max(maxRight, height[i+1]);
            maxRightNums[i] = maxRight;
        }

        int water = 0;
        for (int i=0; i<n; i++) {
            int minLR = min(maxLeftNums[i], maxRightNums[i]);
            if (minLR > height[i]) {
                water += (minLR - height[i]);
            }
        }
        return water;
    }
};