class Solution 
{
    public:
    // score of a pair (i < j) of sightseeing spots is 
    // values[i] + values[j] + i - j
    // or, values[i] + i + values[j] - j
    // the sum of the values of the sightseeing spots, 
    // minus the distance between them.
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        if (values.empty()) return 0;
        int n = values.size();

        int res = INT_MIN;
        int maxLeft = values[0]+0;

        for (int j=1; j<n; j++) {
            res = max(res, maxLeft+values[j]-j);
            maxLeft = max(maxLeft, values[j]+j);
        }
        return res;
    }
};