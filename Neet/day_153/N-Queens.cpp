


// Time: O( N! )
// Space: O(N ^ 2)

class Solution 
{
    public:
    vector<vector<string>> solveNQueens(int n) 
    {
        // init the dp
        vector<string> board(n, string(n, '.'));
        dfs(0, n, board);
        return res;
    }
    private:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> diagonal1;
    unordered_set<int> diagonal2;

    void dfs(int row, int n, vector<string>& currPath) 
    {
        if (row == n) {
            res.push_back(currPath);
            return;
        }

        // fill the row
        for (int c=0; c<n; c++) {
            int d1 = row+c;
            int d2 = row-c;

            if (cols.count(c) || diagonal1.count(d1) || diagonal2.count(d2)) continue;

            if (currPath[row][c] == '.') {
                // fill the pos
                currPath[row][c] = 'Q';
                cols.insert(c);
                diagonal1.insert(d1);
                diagonal2.insert(d2);

                // recurse
                dfs(row+1, n, currPath);

                currPath[row][c] = '.';
                cols.erase(c);
                diagonal1.erase(d1);
                diagonal2.erase(d2);
            }
        }
    }
};