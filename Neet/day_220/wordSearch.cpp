class Solution 
{
    public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        ROW = board.size();
        COL = board[0].size();

        // pruning 1:
        if (ROW * COL < word.length()) return false;

        // pruning 2:
        // countingSort
        vector<int> needFreq(128, 0);
        vector<int> boardFreq(128, 0);

        for (char ch : word) {
            needFreq[ch]++;
        }
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                boardFreq[board[r][c]]++;
            }
        }
        for (int i=0; i<128; i++) {
            if (needFreq[i] > boardFreq[i]) return false;
        }

        // pruning 3:
        if (boardFreq[word.back()] > boardFreq[word[0]]) {
            reverse(word.begin(), word.end());
        }

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == word[0]) {
                    char originalChar = board[r][c];
                    board[r][c] = '#';
                    if (dfs(r, c, 1, word, board)) return true;
                    board[r][c] = originalChar;
                }
            }
        }
        return false;
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };

    bool dfs(int row, int col, int currIdx, const string& word, vector<vector<char>>& board)
    {
        if (currIdx == word.length()) {
            return true;
        }

        for (auto& DIR : DIRS) {
            int newR = row+DIR.first;
            int newC = col+DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] != word[currIdx]) continue;
            char originalChar = board[newR][newC];
            board[newR][newC] = '#'; // mark as visited
            if (dfs(newR, newC, currIdx+1, word, board)) return true;
            board[newR][newC] = originalChar; 
        }

        return false;
    }
};