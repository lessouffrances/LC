
// [[5,4],[6,4],[6,7],[2,3]]
// [2,3] [5,4] [6,7] [6,4]

class Solution 
{
    public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        if (envelopes.empty()) return 0;

        // sort in asc in width, sort in desc in height
        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b){
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        vector<int> dp;
        for (auto& env : envelopes) {
            int h = env[1];
            auto iter = lower_bound(dp.begin(), dp.end(), h);
            if (iter == dp.end()) {
                dp.push_back(h);
            } else {
                *iter = h;
            }
        }
        return dp.size();
    }
};