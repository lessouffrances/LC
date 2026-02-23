



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
    unordered_set<int> cols;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    vector<vector<string>> res;
    void dfs(vector<string>& currBoard, int currRow, int n)
    {
        if (currRow == n) {
            res.push_back(currBoard);
            return;
        }

        for (int col=0; col<n; col++) {
            int d1 = currRow+col;
            int d2 = currRow-col;

            if (cols.count(col) || diag1.count(d1) || diag2.count(d2)) continue;

            // fill this pos 
            currBoard[currRow][col] = 'Q';
            cols.insert(col);
            diag1.insert(d1);
            diag2.insert(d2);

            dfs(currBoard, currRow+1, n);

            currBoard[currRow][col] = '.';
            cols.erase(col);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }
};