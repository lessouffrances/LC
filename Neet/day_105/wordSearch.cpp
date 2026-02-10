class Solution 
{
    public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        ROW = board.size();
        COL = board[0].size();

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == word[0]) {
                    string startPath = "";
                    startPath.push_back(board[r][c]);
                    char originalChar = board[r][c];
                    board[r][c] = '#';
                    if (dfs(0, r, c, startPath, board, word)) return true;
                    board[r][c] = originalChar;
                }
            }
        }
        return false;
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(int idx, int row, int col, string& currPath, vector<vector<char>>& board, const string& word)
    {
        if (currPath == word) {
            return true;
        }

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] == '#') continue;
            if (board[newR][newC] != word[idx+1]) continue;

            char originalChar = board[newR][newC]; 
            board[newR][newC] = '#'; // mark visited
            currPath.push_back(originalChar);

            if (dfs(idx+1, newR, newC, currPath, board, word)) return true;

            board[newR][newC] = originalChar; // backtrack
            currPath.pop_back();
        }

        return false;
    }
};