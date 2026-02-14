class Solution 
{
    public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> initBoard(n, string(n, '.'));
        dfs(initBoard, 0, n);
        return res;
    }
    private:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> diagonal1;
    unordered_set<int> diagonal2;
    void dfs(vector<string>& currBoard, int row, int n)
    {
        if (row == n) {
            res.push_back(currBoard);
            return;
        }
        
        for (int col=0; col<n; col++) {
            int d1 = row-col;
            int d2 = row+col;

            if (cols.count(col) || diagonal1.count(d1) || diagonal2.count(d2)) continue;

            // fill
            currBoard[row][col] = 'Q';
            cols.insert(col);
            diagonal1.insert(d1);
            diagonal2.insert(d2);
            // recurse
            dfs(currBoard, row+1, n);

            currBoard[row][col] = '.';
            cols.erase(col);
            diagonal1.erase(d1);
            diagonal2.erase(d2); // backtrack
        }
    }
};