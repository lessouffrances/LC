class Solution 
{
    public:
    int countBattleships(vector<vector<char>>& board) 
    {
        if (board.empty()) return 0;
        ROW = board.size();
        COL = board[0].size();
        
        int numOfBattleships = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == 'X') {
                    board[r][c] = '#';
                    dfs(r, c, board);
                    numOfBattleships++;
                }
            }
        }
        return numOfBattleships;
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{1,0}, {0,1}};
    void dfs(int row, int col, vector<vector<char>>& board)
    {
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] != 'X') continue;

            board[newR][newC] = '#'; // mark visited;
            dfs(newR, newC, board);
        }
    }
};