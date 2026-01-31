class Solution
{
    public: 
    bool exist(vector<vector<char>>& board, string s)
    {
        if (board.empty() || s.length() == 0) return false;
        ROW = board.size();
        COL = board[0].size();

        if (ROW == 1 && COL == 1 && string{board[0][0]} == s) return true;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == s[0]) {
                    if (dfs(r, c, 0, board, s)) return true;
                }
            }
        }
        return false;
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{-1,0},{1,0},{0,-1},{0,1}};
    bool dfs(int row, int col, int idx, vector<vector<char>>& board, const string& s)
    {
        if (idx == s.length()) return true;
        if (board[row][col] != s[idx]) return false;

        char temp = board[row][col];
        board[row][col] = '#';

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (dfs(newR, newC, idx+1, board, s)) return true;
        }

        board[row][col] = temp;
        return false;
    }
};