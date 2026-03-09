


// Time: O (n! * n^2)
// Space: O(n^2)

class Solution 
{
    public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> currBoard(n, string(n, '.'));
        dfs(0, currBoard, n);
        return res;
    }
    private:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> diagonal1;
    unordered_set<int> diagonal2;

    void dfs(int row, vector<string>& currBoard, int n)
    {
        if (row == n) {
            res.push_back(currBoard);
            return;
        }

        // fill this row
        for (int c=0; c<n; c++) {
            int d1 = row+c;
            int d2 = row-c;

            if (cols.count(c) || diagonal1.count(d1) || diagonal2.count(d2)) continue;

            // fill this cell
            currBoard[row][c] = 'Q';
            cols.insert(c);
            diagonal1.insert(d1);
            diagonal2.insert(d2);

            dfs(row+1, currBoard, n);
            // backtrack
            cols.erase(c);
            diagonal1.erase(d1);
            diagonal2.erase(d2);
            currBoard[row][c] = '.';
        }
    }
};