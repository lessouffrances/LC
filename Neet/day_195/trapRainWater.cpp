
// height =    [4,2,0,3,2,5]
// maxLeft =  [0,4,4,4,4,4]
// maxRight= [5,5,5,5,5,5]
// minLR =  [0,4,4,4,4,4]
// water = [0,2,4,1,2,1] = 5
class Solution 
{
    public:
    int trap(vector<int>& height) 
    {
        if (height.empty()) return 0;
        int n = height.size();

        // construct maxLeft array
        vector<int> maxLeft(n, 0);
        int maxLeftNum = 0;
        for (int i=1; i<n; i++) {
            maxLeftNum = max(maxLeftNum, height[i-1]);
            maxLeft[i] = maxLeftNum;
        }

        // construct maxRight array
        vector<int> maxRight(n, 0);
        int maxRightNum = 0;
        for (int i=n-2; i>=0; i--) {
            maxRightNum = max(maxRightNum, height[i+1]);
            maxRight[i] = maxRightNum;
        }

        // accumulate water
        int water = 0;
        for (int i=0; i<n; i++) {
            int minLR = min(maxLeft[i], maxRight[i]);
            if (minLR > height[i]) {
                water += (minLR-height[i]);
            }
        }
        return water;
    }
};