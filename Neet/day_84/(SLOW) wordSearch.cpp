class Solution
{
    public: 
    bool exist(vector<vector<char>>& board, string s)
    {
        if (board.empty() || s.length() == 0) return false; 

        ROW = board.size();
        COL = board[0].size();

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == s[0]) {
                    visited.clear();
                    string start(1, board[r][c]);
                    visited.insert( {r, c} );
                    if (dfs(r, c, start, s, board)) return true;
                }
            }
        }
        return false;
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{-1,0},{1,0},{0,-1},{0,1}};
    set<pair<int, int>> visited;
    bool dfs(int row, int col, 
            string& currStr, const string& s, vector<vector<char>>& board)
    {
        if (currStr == s) return true;
        if (currStr.length() >= s.length()) return false;
        if (s.find(currStr) != 0) return false;

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (visited.count( {newR, newC} )) continue;

            currStr += board[newR][newC];
            visited.insert( {newR, newC} );
            if (dfs(newR, newC, currStr, s, board)) return true;
            currStr.pop_back(); // backtrack
            visited.erase( {newR, newC} );
        }
        return false;
    }

};