class Solution 
{
    public:
    bool judgeCircle(string moves) 
    {
        return dfs(0, 0, 0, moves);
    }
    private:
    bool dfs(int idx, int row, int col, const string& moves)
    {
        if (idx == moves.length() 
        && row == 0 && col == 0) return true;

        if (moves[idx] == 'U') {
            return dfs(idx+1, row-1, col, moves);
        } else if (moves[idx] == 'D') {
            return dfs(idx+1, row+1, col, moves);
        } else if (moves[idx] == 'L') {
            return dfs(idx+1, row, col-1, moves);
        } else if (moves[idx] == 'R') {
            return dfs(idx+1, row, col+1, moves);
        }
        return false;
    }
};