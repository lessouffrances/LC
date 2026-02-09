class Solution
{
    public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        vector<vector<int>> histograms = buildHistograms(matrix);

        int maxArea = 0;
        for (auto& row : histograms) {
            // for each row, use largest histogram algorithm
            stack<pair<int, int>> deck;
            int n = row.size();

            for (int i=0; i<n; i++) {
                int start = i;
                int h = row[i];

                while (!deck.empty() && h < deck.top().second) {
                    auto [idx, height] = deck.top();
                    deck.pop();
                    maxArea = max(maxArea, (i - idx) * height);
                    start = idx;
                }
                deck.push( {start, h} );
            }

            while (!deck.empty()) {
                auto& [idx, height] = deck.top();
                deck.pop();

                maxArea = max(maxArea, (int)(n-idx) * height);
            }
        }

        return maxArea;
    }
    private:
    int ROW, COL;
    vector<vector<int>> buildHistograms(vector<vector<char>>& matrix)
    {
        if (matrix.size() == 0) return {};
        ROW = matrix.size();
        COL = matrix[0].size();

        vector<vector<int>> dp(ROW, vector<int>(COL, 0));
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (matrix[r][c] == '0') continue;

                int upper = (r-1) >= 0 ? dp[r-1][c] : 0;
                dp[r][c] = 1 + upper;
            }
        }
        return dp;
    }
};