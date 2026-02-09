













class Solution 
{
    public:
    int minDeletionSize(vector<string>& strs) 
    {
        if (strs.empty()) return 0;

        int ROW = strs.size();
        int COL = strs[0].size();
        int deleteCount = 0;

        // keep track of which rows are already < next row
        vector<bool> sorted(ROW-1, false);

        for (int c=0; c<COL; c++) {
            // check if the deleting this col 
            bool shouldDelete = false;
            for (int r=0; r<ROW-1; r++) {
                if (sorted[r]) continue;

                // if the char on this row is > next row's char, must delete the col
                if (strs[r][c] > strs[r+1][c]) {
                    shouldDelete = true;
                    break;
                }
            }
            if (shouldDelete) {
                deleteCount++;
            } else {
                for (int r=0; r<ROW-1; r++) {
                    if (r+1 < ROW && strs[r][c] < strs[r+1][c]) {
                        sorted[r] = true;
                    }
                }
            }
        }
        return deleteCount;
    }
};