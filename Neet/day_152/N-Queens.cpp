




// Queen Rule: Queen can attack any other queen on the same col and its two diagonal lines
// Time: O( N! )
// Space: O( N^2 ), for init the board
class Solution 
{
    public:
    vector<vector<string>> solveNQueens(int n) 
    {
        // init the board
        vector<string> board = vector(n, string(n, '.'));
        dfs(0, board, n);
        return res;
    }

    private:

    unordered_set<int> cols;
    unordered_set<int> diagonal1;
    unordered_set<int> diagonal2;

    vector<vector<string>> res;
    void dfs(int row, vector<string>& currBoard, int n)
    {
        if (row == n) {
            res.push_back(currBoard);
            return;
        }

        for (int c=0; c<n; c++) {
            int d1 = row+c;
            int d2 = row-c;
            if (cols.count(c) || diagonal1.count(d1) || diagonal2.count(d2)) continue;

            // fill this pos with Q
            currBoard[row][c] = 'Q';
            cols.insert(c);
            diagonal1.insert(d1);
            diagonal2.insert(d2);

            dfs(row+1, currBoard, n);

            // backtrack
            currBoard[row][c] = '.';
            cols.erase(c);
            diagonal1.erase(d1);
            diagonal2.erase(d2);
        }
    }
};