class Solution 
{
    public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        if (board.empty() || word.length() == 0) return false;
        ROW = board.size();
        COL = board[0].size();

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == word[0]) {
                    char originalChar = board[r][c];
                    board[r][c] = '#'; // mark as visited
                    if (dfs(r, c, 1, board, word)) return true;
                    board[r][c] = originalChar; // backtrack on board
                }
            }
        }
        return false;
    }

    private:
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int ROW, COL;
    bool dfs(int row, int col, int currIdx, vector<vector<char>>& board, const string& word)
    {
        // base case
        if (currIdx == word.length()) return true;
        
        for (auto& DIR : DIRS) {
            int newR = row+DIR.first;
            int newC = col+DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] != word[currIdx]) continue;

            char originalChar = board[newR][newC];
            board[newR][newC] = '#'; // mark as visited
            if (dfs(newR, newC, currIdx+1, board, word)) return true;
            board[newR][newC] = originalChar; // backtrack on board
        }

        return false;
    }
};
