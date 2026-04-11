





class Solution 
{
    public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) return 0;
        ROW = matrix.size();
        COL = matrix[0].size();

        buildHistograms(matrix);

        int maxRec = 0;
        for (int r=0; r<ROW; r++) {
            stack<pair<int, int>> deck;
            for (int c=0; c<COL; c++) {
                int start = c;
                int h = histogram[r][c];
                while (!deck.empty() && h < deck.top().second) {
                    auto [idx, height] = deck.top();
                    deck.pop();
                    maxRec = max(maxRec, (c-idx)*height);
                    start = idx;
                }
                deck.push( {start, h} );
            }
            while (!deck.empty()) {
                auto [idx, height] = deck.top();
                deck.pop();
                maxRec = max(maxRec, (COL-idx)*height);
            }
        }
        return maxRec;
    }

    private:
    int ROW, COL;
    vector<vector<int>> histogram;
    void buildHistograms(vector<vector<char>>& matrix)
    {
        histogram.assign(ROW, vector<int>(COL, 0));

        // for the first row
        for (int c=0; c<COL; c++) {
            histogram[0][c] = matrix[0][c]-'0';
        }

        for (int r=1; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (matrix[r][c] == '0') continue;
                histogram[r][c] = (matrix[r][c]-'0') + histogram[r-1][c];
            }
        }
    }
};