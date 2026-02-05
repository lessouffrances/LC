class Solution 
{
    public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        if (score.empty()) return {};

        int n = score.size();
        // sort the score in descending order with idxes
        vector<pair<int, int>> idxAndScore;
        for (int i=0; i<n; i++) {
            idxAndScore.push_back( {i, score[i]} );
        }
        sort(idxAndScore.begin(), idxAndScore.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        vector<string> rank(n, " ");
        for (int i=0; i<n; i++) {
            auto [idx, score] = idxAndScore[i];
            if (i == 0) {
                rank[idx] = "Gold Medal";
                continue;
            } else if (i == 1) {
                rank[idx] = "Silver Medal";
                continue;
            } else if (i == 2) {
                rank[idx] = "Bronze Medal";
                continue;
            }

            rank[idx] = to_string(i+1);
        }
        
        return rank;
    }
};