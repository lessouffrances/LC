class Solution 
{
    public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        if (board.empty()) return false;

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        int ROW = board.size();
        int COL = board[0].size();

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                char num = board[r][c];

                if (num == '.') continue;

                int boxIdx = (r / 3) * 3 + (c / 3);
                if (rows[r].count(num) || cols[c].count(num) || boxes[boxIdx].count(num)) {
                    retur false;
                }

                rows[r].insert(num);
                cols[c].insert(num);
                boxes[boxIdx].insert(num);
            }
        }
        return true;
    }
};