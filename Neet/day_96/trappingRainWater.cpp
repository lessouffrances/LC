class Solution 
{
    public:
    int trap(vector<int>& height)
    {
        if (height.empty()) return 0;
        int n = height.size();

        vector<int>maxLeft(n+1);
        vector<int>maxRight(n+1);
        maxLeft[0] = 0;
        maxRight[n] = 0;

        int maxLeftNum = INT_MIN;
        for (int i=1; i<n+1; i++) {
            maxLeftNum = max(maxLeftNum, height[i-1]);
            maxLeft[i] = maxLeftNum;
        }
        int maxRightNum = INT_MIN;
        for (int i=n-1; i>=0; i--) {
            maxRightNum = max(maxRightNum, height[i]);
            maxRight[i] = maxRightNum;
        }

        int water = 0;
        for (int i=0; i<n; i++) {
            int minLR = min(maxLeft[i], maxRight[i]);
            if (minLR > height[i]) {
                water += minLR - height[i];
            }
        }
        
        return water;
    }
};