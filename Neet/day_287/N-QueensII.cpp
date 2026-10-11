class Solution 
{
    public:
    int totalNQueens(int n) 
    {
        vector<string> currPath = vector<string>(n, string(n, '.'));
        dfs(0, currPath, n);
        return count;
    }

    private:
    unordered_set<int> cols;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    int count = 0;

    void dfs(int row, vector<string>& currPath, int n) 
    {
        if (row == n) {
            count++;
            return;
        }

        for (int c=0; c<n; c++) {
            int d1 = row+c;
            int d2 = row-c;

            if (cols.count(c) || diag1.count(d1) || diag2.count(d2)) continue;
            currPath[row][c] = 'Q';
            cols.insert(c);
            diag1.insert(d1);
            diag2.insert(d2);

            dfs(row+1, currPath, n);

            currPath[row][c] = '.';
            cols.erase(c);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }
};