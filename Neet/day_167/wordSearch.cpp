class Solution 
{
    public:
    bool exist(vector<vector<char>>& board, string word) 
    {s
        if (board.empty() || word.length() == 0) return false;

        ROW = board.size();
        COL = board[0].size();

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (word[0] == board[r][c]) {
                    // visited.insert({r, c});
                    char original = board[r][c];
                    board[r][c] = '#';
                    if (dfs(r, c, 1, board, word)) return true;
                    board[r][c] = original;
                }
            }
        }
        return false;
    }

    private:
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int ROW, COL;
    set<pair<int, int>> visited;

    bool dfs(int row, int col, int currIdx, vector<vector<char>>& board, string word)
    {
        // base case
        if (currIdx == word.length()) {
            return true;
        }

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (visited.count({newR, newC})) continue;
            if (board[newR][newC] != word[currIdx]) continue;

            char original = board[newR][newC];
            board[newR][newC] = '#';
            if (dfs(newR, newC, currIdx+1, board, word)) return true;
            board[newR][newC] = original;
        }

        return false;
    }
};