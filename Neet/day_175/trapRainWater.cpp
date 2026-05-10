class Solution 
{
    public:
    int trap(vector<int>& height) 
    {
        if (height.empty()) return 0;
        int n = height.size();

        vector<int> maxLeft(n);
        int maxLeftNum = INT_MIN;
        maxLeft[0] = 0;
        for (int i=1; i<n; i++) {
            maxLeftNum = max(maxLeftNum, height[i-1]);
            maxLeft[i] = maxLeftNum;
        }

        vector<int> maxRight(n);
        int maxRightNum = INT_MIN;
        maxRight[n-1] = 0;
        for (int i=n-2; i>=0; i--) {
            maxRightNum = max(maxRightNum, height[i+1]);
            maxRight[i] = maxRightNum;
        }

        int water = 0;
        for (int i=0; i<n; i++) {
            int minLR = min(maxLeft[i], maxRight[i]);
            if (minLR > height[i]) {
                water += (minLR - height[i]);
            }
        }
        return water;
    }
};