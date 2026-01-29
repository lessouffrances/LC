class Solution 
{
    public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string>board(n, string(n, '.'));

        dfs(0, n, board);
        return res;
    }
    private: 
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> diagonal1;
    unordered_set<int> diagonal2;
    void dfs(int row, int n, vector<string>& board)
    {
        if (row == n) {
            res.push_back(board);
            return;
        } 

        for (int col=0; col<n; col++) {
            int d1 = row - col;
            int d2 = row + col;

            if (cols.count(col) || diagonal1.count(d1) || diagonal2.count(d2)) continue;

            board[row][col] = 'Q';
            cols.insert(col);
            diagonal1.insert(d1);
            diagonal2.insert(d2);

            dfs(row+1, n, board);

            // backtrack
            board[row][col] = '.';
            cols.erase(col);
            diagonal1.erase(d1);
            diagonal2.erase(d2);
        }
    }
};