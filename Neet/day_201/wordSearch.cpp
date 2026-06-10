class Solution 
{
    public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        if (board.empty()) return false;

        ROW = board.size();
        COL = board[0].size();

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == word[0]) {
                    if (dfs(r, c, 1, board, word)) return true;
                }
            }
        }
        return false;
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    bool dfs(int row, int col, int currIdx, vector<vector<char>>& board, string word)
    {
        if (currIdx == word.length()) {
            return true;
        }

        char original = board[row][col];
        board[row][col] = '#'; // visited
        for (auto& DIR : DIRS) {
            int newR = row+DIR.first;
            int newC = col+DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] != word[currIdx]) continue;
            if (dfs(newR, newC, currIdx+1, board, word)) {
                board[row][col] = original;
                return true; 
            }
        }
        board[row][col] = original;
        return false;
    }
};