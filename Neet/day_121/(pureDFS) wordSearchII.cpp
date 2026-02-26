


class Solution 
{
    public:
    // the board can be reused => visited tracker is local to each word
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        if (words.empty() || board.empty()) return {};

        ROW = board.size();
        COL = board[0].size();

        vector<string> res;
        for (auto& word : words) {
            if (findOneWord(word, board)) {
                res.push_back(word);
            }
        }
        return res;
    }
    private:
    int ROW, COL;
    vector<vector<bool>> visited;
    vector<pair<int, int>> DIRS = { {0,1},{0,-1},{1,0},{-1,0} };

    bool findOneWord(const string& word, vector<vector<char>>& board)
    {
        // reset board
        visited.clear();
        visited.assign(ROW, vector<bool>(COL, false));

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == word[0]) {
                    visited[r][c] = true;
                    if (dfs(r, c, 1, word, board)) return true;

                    visited[r][c] = false; // backtrack for subsequent calls
                }
            }
        }
        return false;
    }

    // findOneWord will call:
    bool dfs(int row, int col, int idx,  
        const string& word, vector<vector<char>>& board)
    {
        if (idx == word.length()) return true;

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (visited[newR][newC]) continue;
            // check for char match
            if (word[idx] != board[newR][newC]) continue;

            visited[newR][newC] = true;
            if (dfs(newR, newC, idx+1, word, board)) return true;

            visited[newR][newC] = false; // backtrack!
        }

        return false;
    }
};