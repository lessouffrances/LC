







class Solution 
{
    public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        if (score.empty()) return {};
        int n = score.size();

        vector<pair<int, int>> scoreWithIdx; // { score, idx }
        for (int i=0; i<n; i++) {
            scoreWithIdx.push_back( {score[i], i} );
        }

        // sort based on score
        sort(scoreWithIdx.begin(), scoreWithIdx.end(), [](const auto& a, const auto& b){
            return a.first > b.first;
        });

        vector<string> res(n);
        for (int i=0; i<n; i++) {
            int idx = scoreWithIdx[i].second;
            if (i==0) {
                res[idx] = "Gold Medal";
                continue;
            }
            if (i==1) {
                res[idx] = "Silver Medal";
                continue;
            }
            if (i==2) {
                res[idx] = "Bronze Medal";
                continue;
            }
            res[idx] = to_string(i+1);
        }
        return res;
    }
};