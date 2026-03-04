class Solution 
{
    public:
    int trap(vector<int>& height) 
    {
        int n = height.size();

        // build maxLeft
        vector<int> maxLeftNum(n+1, 0);
        maxLeftNum[0] = 0
        int maxLeftNum;
        for (int i=1; i<n; i++) {
            maxLeftNum = max(maxLeftNum, nums[i-1]);
            maxLeft.push_back(maxLeftNum);
        }

        // build maxRight
        vector<int> maxRightNum(n+1, 0);
        maxRightNum[n] = 0;
        int maxRightNum;
        for (int i=n-1; i>=0; i--) {
            maxRightNum = max(maxRightNum, nums[i]);
            maxRightNum.push_back(maxRightNum);
        }

        int water = 0;
        for (int i=0; i<n; i++) {
            int minLR = min(maxLeft[i], maxRight[i]);
            if (height < minLR) {
                water += minLR-height;
            }
        }
        return water;
    }
}