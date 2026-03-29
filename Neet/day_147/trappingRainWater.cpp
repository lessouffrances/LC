


class Solution 
{
    public:
    int trap(vector<int>& height) 
    {
        if (height.size() == 0) return 0;
        int n = height.size();

        // build maxLeft
        vector<int> maxLeft(n);
        maxLeft[0] = 0;
        int maxLeftNum = INT_MIN;
        for (int i=1; i<n; i++) {
            maxLeftNum = max(maxLeftNum, height[i-1]);
            maxLeft[i] = maxLeftNum;
        }

        // build maxRight
        vector<int> maxRight(n);
        maxRight[n-1] = 0;
        int maxRightNum = INT_MIN;
        for (int i=n-2; i>=0; i--) {
            maxRightNum = max(maxRightNum, height[i+1]);
            maxRight[i] = maxRightNum;
        }

        int water = 0;
        for (int i=0; i<n; i++) {
            int minLR = min(maxLeft[i], maxRight[i]);
            water += max(0, minLR-height[i]);
        }
        return water;
    }
};