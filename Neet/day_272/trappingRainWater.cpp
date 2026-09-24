class Solution 
{
    public:
    int trap(vector<int>& height) 
    {
        if (height.empty()) return 0;
        int n = height.size();

        // build maxLeft
        int maxLeftNum = INT_MIN;
        vector<int> maxLeft(n, 0); // self-exclusive
        for (int i=1; i<n; i++) {
            maxLeftNum = max(maxLeftNum, height[i-1]);
            maxLeft[i] = maxLeftNum;
        }
        
        // build maxRight
        int maxRightNum = INT_MIN;
        vector<int> maxRight(n, 0); // self-exclusive
        for (int i=n-2; i>=0; i--) {
            maxRightNum = max(maxRightNum, height[i+1]);
            maxRight[i] = maxRightNum;
        }

        int water = 0;
        for (int i=1; i<n-1; i++) {
            int minLR = min(maxLeft[i], maxRight[i]);
            if (minLR > height[i]) water += (minLR-height[i]); 
        }
        return water;
    }
};