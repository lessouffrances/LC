


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
                    char temp = board[r][c];
                    board[r][c] = '#'; // mark the word[0] as visited
                    if (dfs(r, c, 1, word, board)) return true;
                    board[r][c] = temp; // backtrack
                }
            }
        }
        return false;
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {0,1},{0,-1},{1,0},{-1,0} };

    bool dfs(int row, int col, int currIdx, const string& word, vector<vector<char>>& board) {
        if (currIdx == word.length()) return true;

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;
            
            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] != word[currIdx]) continue;
            
            char temp = board[newR][newC];
            board[newR][newC] = '#'; // mark visited;
            if (dfs(newR, newC, currIdx+1, word, board)) return true;
            board[newR][newC] = temp; // backtrack
        }
        return false;
    }
};