class Solution 
{
    public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        dfs(0, n, board);
        return res;
    }

    private:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    void dfs(int row, int n, vector<string>& currBoard)
    {
        if (row == n) {
            res.push_back(currBoard);
            return;
        }

        for (int col=0; col<n; col++) {
            int d1 = row-col;
            int d2 = row+col;

            if (cols.count(col) || diag1.count(d1) || diag2.count(d2)) continue;
            
            currBoard[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(d1);
            diag2.insert(d2);

            dfs(row+1, n, currBoard);

            currBoard[row][col] = '.';
            cols.erase(col);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }
};