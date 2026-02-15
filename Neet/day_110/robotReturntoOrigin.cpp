




class Solution 
{
    public:
    bool judgeCircle(string moves) 
    {
        if (moves.length() == 0) return true;

        pair<int, int> pos = dfs(0, 0, 0, moves);
        return pos.first == 0 && pos.second == 0;
    }
    private:
    pair<int, int> dfs(int idx, int row, int col, string& moves)
    {
        // base case
        if (idx == moves.length()) {
            return {row, col};
        }

        if (moves[idx] == 'R') {
            return dfs(idx+1, row, col+1, moves);
        } else if (moves[idx] == 'L') {
            return dfs(idx+1, row, col-1, moves);
        } else if (moves[idx] == 'U') {
            return dfs(idx+1, row-1, col, moves);
        } else if (moves[idx] == 'D') {
            return dfs(idx+1, row+1, col, moves);
        } 
        return {-1, -1}; // invalid move
    }
};