class Solution 
{
    public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        if (values.empty()) return 0;
        int n = values.size();
        // i < j and values[i] + values[j] + i - j
        // values[i] + i is the left value
        // values[j] - j is the right value
        // want both of these to be large
        int maxLeft = values[0]+0;
        int res = INT_MIN;
        for (int j=1; j<n; j++) {
            res = max(res, maxLeft+values[j]-j);
            // update left value
            maxLeft = max(maxLeft, values[j]+j);
        }
        return res;
    }
};