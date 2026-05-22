class Solution 
{
    public:
    // score of a pair (i < j) of sightseeing spots is 
    // values[i] + values[j] + i - j
    // the sum of the values of the sightseeing spots, 
    // minus the distance between them.
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        if (values.empty()) return 0;
        int n = values.size();

        int res = INT_MIN;

        for (int i=0; i<n-1; i++) {
            for (int j=i+1, j<n; j++) {
                int currScore = values[i] + values[j] + i - j;
                res = max(currScore, res);
            }
        }
        return res;
    }
};