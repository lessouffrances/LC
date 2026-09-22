class Solution 
{
    public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int ROW = board.size();
        int COL = board[0].size();

        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> boxes(9);

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                char num = board[r][c];
                if (num == '.') continue;

                int boxID = 3 * (r/3) + (c/3);
                if (rows[r].count(num) || cols[c].count(num) || boxes[boxID].count(num)) 
                return false;

                rows[r].insert(num);
                cols[c].insert(num);
                boxes[boxID].insert(num);
            }
        }
        return true;
    }
};