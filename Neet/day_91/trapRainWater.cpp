class Solution 
{
    public:
    int trap(vector<int>& height)
    {
        if (height.empty()) return 0;
        int n = height.size();

        // maxLeft
        vector<int>maxLeft(n, 0);
        int maxLeftNum = INT_MIN;
        for (int i=1; i<n; i++) {
            maxLeftNum = max(height[i-1], maxLeftNum);
            maxLeft[i] = maxLeftNum;
        }

        // maxRight
        vector<int>maxRight(n, 0);
        int maxRightNum = INT_MIN;
        for (int i=n-2; i>=0; i--) {
            maxRightNum = max(height[i+1], maxRightNum);
            maxRight[i] = maxRightNum;
        }

        int water = 0;
        for (int i=0; i<n; i++) {
            int minLR = min(maxLeft[i], maxRight[i]);
            if (height[i] < minLR) {
                water += (minLR - height[i]);
            }
        }

        return water;
    }
};