class Solution 
{
    public:
    int minDeletionSize(vector<string>& strs) 
    {
        if (strs.empty()) return 0;

        int ROW = strs.size();
        int COL = strs[0].size();
        int deleteCount = 0;

        vector<bool> sorted(ROW-1, false);

        for (int c=0; c<COL; c++) {
            bool shouldDelete = false;
            for (int r=0; r<ROW-1; r++) {
                if (sorted[r]) continue;

                if (strs[r][c] > strs[r+1][c]) {
                    shouldDelete = true;
                    break;
                }
            }
            if (shouldDelete) {
                deleteCount++;
            } else {
                // if there is no col need to be delete, fill the col with true
                for (int r=0; r<ROW-1; r++) {
                    if (strs[r][c] < strs[r+1][c]) {
                        sorted[r] = true;
                    }
                }
            }
        }
        return deleteCount;
    }
};