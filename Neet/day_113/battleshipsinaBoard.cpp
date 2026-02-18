class Solution 
{
    public:
    int countBattleships(vector<vector<char>>& board) 
    {
        if (board.empty()) return 0;
        ROW = board.size();
        COL = board[0].size();

        int numOfBattleShips = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == 'X') {
                    board[r][c] = 2;
                    dfs(r, c, board);
                    numOfBattleShips++;
                }
            }
        }
        return numOfBattleShips;
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{0,1},{1,0}};
    void dfs(int row, int col, vector<vector<char>>& board)
    {
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] != 'X') continue;
            board[newR][newC] = '2';
            dfs(newR, newC, board);
        }
    }
};