class Solution 
{
    public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n, string(n, "."));
        dfs(0, n, board);
        return res;
    }

    private:
    vector<vector<string>> res;
    // Queens cannot appera on the same row, same col, same diag 
    unordered_set<int> cols;
    unordered_set<int> rows;
    unordered_set<int> diag1;
    unordered_set<int> diag2;

    void dfs(int row, int n, vector<string>& currPath) 
    {
        if (row == n) {
            res.push_back(currPath);
            return;
        }

        // fill the row
        for (int c=0; c<9; c++) {
            int d1 = row-c;
            int d2 = row+c;

            if (cols.count(c) ||  diag1.count(d1) || diag2.count(d2)) continue;
            if (currPath[row][c] == '.') {
                currPath[row][c] = 'Q';
                cols.insert(c);
                rows.insert(row);
                diag1.insert(d1);
                diag2.insert(d2);

                dfs(row+1, n, currPath);

                currPath[row][c] = '.';
                cols.erase(c);
                diag1.erase(d1);
                diag2.erase(d2);
            }
        }
    }
};
