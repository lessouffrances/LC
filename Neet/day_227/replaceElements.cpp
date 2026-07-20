class Solution 
{
    public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        // construct maxRight
        int n = arr.size();
        vector<int> maxRight(n, -1);
        int maxRightNum = INT_MIN;

        for (int i=n-2; i>=0; i--) {
            maxRightNum = max(maxRightNum, arr[i+1]);
            maxRight[i] = maxRightNum;
        }

        return maxRight;
    }
};