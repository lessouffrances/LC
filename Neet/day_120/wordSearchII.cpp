



class Solution 
{
    public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        if (words.empty() || board.empty()) return {};

        ROW = board.size();
        COL = board[0].size();

        
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {0,1},{0,-1},{1,0},{-1,0} };
    bool dfs(int row, int col, string& currPath, int idx,  
        const string& word, vector<vector<char>>& board)
    {
        if (idx == word.length()) return true;

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if ()
        }
    }
};