class Solution
{
    public:
    int findTheSmallestMaximumValueAmongstAllPath(vector<int>& A, vector<int>& B)
    {
        if (A.empty() || B.empty()) return -1;
        if (A.size() != B.size()) return -1;

        COL = A.size();
        MATRIX.push_back(A);
        MATRIX.push_back(B);

        best = INT_MAX;
        dfs(0, 0, INT_MIN);
        return best;
    }

    private:
    int ROW = 2;
    int COL;
    vector<vector<int>> MATRIX;
    vector<vector<int>> DIRS = { {1,0}, {0,1} };
    int best;

    void dfs(int row, int col, int maxVal)
    {
        maxVal = max(maxVal, MATRIX[row][col]);

        if (row == ROW-1 && col == COL-1) {
            best = min(best, maxVal);
            return;
        }

        for (auto& DIR : DIRS) {
            int newR = row + DIR[0];
            int newC = col + DIR[1];

            if (newR >= ROW || newC >= COL) continue;
            dfs(newR, newC, maxVal);
        }
    }
};