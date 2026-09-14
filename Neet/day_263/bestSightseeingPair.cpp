
// index relation: i < j
// dist: j-i
// values = values[i]+values[j]-(j-i)
//        = values[i]+values[j]+(i-j)
//        = values[i]+i+values[j]-j

class Solution 
{
    public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        if (values.empty()) return 0;
        int n = values.size();

        int maxLeft = values[0]+0;
        int res = INT_MIN;
        for (int j=1; j<n; j++) {
            res = max(res, values[j]-j+maxLeft);
            maxLeft = max(maxLeft, values[j]+j);
        }
        return res;
    }
};