

// solve the board row by row
class Solution 
{
    public:
    int totalNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, n);
        return res.size();
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
        
        // fill this row
        for (int col=0; col<n; col++) {
            int d1 = row+col;
            int d2 = row-col;

            if (cols.count(col) || diagonal1.count(d1) || diagonal2.count(d2)) continue;

            // fill this one
            currBoard[row][col] = 'Q';
            cols.insert(col);
            diagonal1.insert(d1);
            diagonal2.insert(d2);
            dfs(currBoard, row+1, n);

            // backtrack
            currBoard[row][col] = '.';
            cols.erase(col);
            diagonal1.erase(d1);
            diagonal2.erase(d2);
        }
    }
};