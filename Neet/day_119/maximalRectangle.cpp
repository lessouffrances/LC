



class Solution 
{
    public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) return 0;
        ROW = matrix.size();
        COL = matrix[0].size();
        buildDP(matrix);

        // do the "largest rectangle in histograms" for each row in dp:
        int maxRec = 0;
        for (int r=0; r<ROW; r++) {

            stack<pair<int, int>> deck; // { idx, height }
            for (int c=0; c<COL; c++) {
                int start = c;
                int h = dp[r][c];

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
    vector<vector<int>> dp;
    int ROW, COL;
    void buildDP(vector<vector<char>>& matrix)
    {
        // init
        dp.assign(ROW, vector<int>(COL, 0));
        // fill the first row first
        for (int c=0; c<COL; c++) {
            dp[0][c] = matrix[0][c]-'0';
        }

        for (int r=1; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (matrix[r][c] == '0') continue;

                dp[r][c] = (matrix[r][c]-'0') + dp[r-1][c]; 
            }
        }
    }
};