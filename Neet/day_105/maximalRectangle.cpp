













class Solution 
{
    public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) return 0;
        ROW = matrix.size();
        COL = matrix[0].size();

        // build histograms
        vector<vector<int>> histograms = buildHistograms(matrix);

        int maxRec = 0;
        for (int row=0; row<ROW; row++) {

            stack<pair<int, int>> deck;
            for (int col=0; col<COL; col++) {
                int start = col;
                int h = histograms[row][col];
                while (!deck.empty() && h < deck.top().second) {
                    auto [idx, height] = deck.top();
                    deck.pop();

                    maxRec = max(maxRec, (col-idx) * height);
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
        // init with 0s
        vector<vector<int>> dp(ROW, vector<int>(COL, 0));

        for (int row=0; row<ROW; row++) {
            for (int col=0; col<COL; col++) {
                if (matrix[row][col] == '0') continue;
                if (row == 0) {
                    dp[row][col] = matrix[row][col]-'0';
                    continue;
                }
                
                dp[row][col] = 1+ dp[row-1][col];
            }
        }

        return dp;
    }
};