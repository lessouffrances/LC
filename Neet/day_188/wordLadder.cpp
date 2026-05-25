

// Time: O(N * M), where N is the # of the wordList, M is the avg size of the word
// Space: O(N)
class Solution 
{
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> wordSet = unordered_set<string>(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);

        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currWord = q.front();
                q.pop();class Solution 
{
    public:
    void solve(vector<vector<char>>& board) 
    {
        ROW = board.size();
        COL = board[0].size();

        // go from the border
        // top row and bottom row
        for (int c=0; c<COL; c++) {
            if (board[0][c] == 'O') {
                dfs(0, c, board);
            }
            if (board[ROW-1][c] == 'O') {
                dfs(ROW-1, c, board);
            }
        }
        // left col and right col
        for (int r=0; r<ROW; r++) {
            if (board[r][0] == 'O') {
                dfs(r, 0, board);
            }
            if (board[r][COL-1] == 'O') {
                dfs(r, COL-1, board);
            }
        }

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }

    private:
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int ROW, COL;
    void dfs(int row, int col, vector<vector<char>>& board)
    {
        board[row][col] = 'T';

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR >= ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] != 'O') continue;
            dfs(newR, newC, board);
        }
    }
};

                if (currWord == endWord) return steps;

                for (int j=0; j<currWord.size(); j++) {
                    char originalChar = currWord[j];
                    for (char ch='a'; ch<='z'; ch++) {
                        if (ch == originalChar) continue;
                        currWord[j] = ch;
                        if (visited.count(currWord) || !wordSet.count(currWord)) continue;
                        q.push(currWord);
                        visited.insert(currWord);
                    }
                    currWord[j] = originalChar;
                }
            }
            steps++;
        }
        return 0;
    }
};