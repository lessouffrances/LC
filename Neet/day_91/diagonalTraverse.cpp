class Solution 
{
    public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        if (mat.empty()) return {};

        ROW = mat.size();
        COL = mat[0].size();

        // all starting poins for dfs are left col and bottom row
        vector<vector<int>> diagonals;
        for (int r=0; r<ROW; r++) {
            vector<int> startDiag;
            diagonals.push_back(dfs(r, 0, startDiag, mat));
        }
        for (int c=1; c<COL; c++) {
            vector<int> startDiag;
            diagonals.push_back(dfs(ROW-1, c, startDiag, mat));
        }

        // reverse the odd-indexed vectors
        for (int i=0; i<diagonals.size(); i++) {
            if (i % 2 != 0) {
                reverse(diagonals[i].begin(), diagonals[i].end());
            }
        }

        vector<int> res; 
        for (auto& diag : diagonals) {
            res.insert(res.end(), diag.begin(), diag.end());
        }
        return res;
    }

    private:
    int ROW, COL;
    vector<int> dfs(int row, int col, vector<int>& diagonal, vector<vector<int>>& mat)
    {
        if (mat.empty()) return {};
        diagonal.push_back(mat[row][col]);

        int newR = row-1;
        int newC = col+1;
        if (newR<0 || newR>=ROW || newC<0 || newC>=COL) {
            return diagonal;
        }
    
        return dfs(newR, newC, diagonal, mat);
    }
};