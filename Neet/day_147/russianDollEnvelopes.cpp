



// [[5,4],[6,4],[6,7],[2,3]]
// [2,3] [5,4] [6,7] [6,4]

// Time: O(N logN)
// Space: O(N)
class Solution 
{
    public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        if (envelopes.empty()) return 0;
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } 
            return a[1] > b[1];
        });

        vector<int> dp; // contains the h of fitting envelopes 
        for (auto& env : envelopes) {
            int h = env[1];
            // binary search for the first index in dp that is > h
            auto it = lower_bound(dp.begin(), dp.end(), h);

            if (it == dp.end()) {
                dp.push_back(h);
            } else {
                *it = h;
            }
        }
        
        return dp.size();
    }
};