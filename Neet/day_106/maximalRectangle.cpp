









class Solution 
{
    public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) return 0;

        ROW = matrix.size();
        COL = matrix[0].size();

        vector<vector<int>> histograms = buildHistograms(matrix);

        int maxRec = 0;
        for (int r=0; r<ROW; r++) {

            stack<pair<int,int>> deck;  // { idx : height }
            for (int c=0; c<COL; c++) {
                int start = c;
                int h = histograms[r][c];

                while (!deck.empty() && h < deck.top().second) {
                    auto [idx, height] = deck.top();
                    deck.pop();

                    maxRec = max(maxRec, (c-idx) * height);
                    start = idx;
                }
                deck.push( {start, h} );
            }

            while (!deck.empty()) {
                auto [idx, height] = deck.top();
                deck.pop();

                maxRec = max(maxRec, (COL-idx) * height);
            }
        }
        return maxRec;
    }
    private:
    int ROW, COL;
    vector<vector<int>> buildHistograms(vector<vector<char>>& matrix)
    {
        vector<vector<int>> dp(ROW, vector<int>(COL, 0));

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (matrix[r][c] == '0' || r == 0) {
                    dp[r][c] = matrix[r][c] - '0';
                    continue;
                }
                dp[r][c] = 1 + dp[r-1][c];
            }
        }
        return dp;
    }
};