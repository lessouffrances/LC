class Solution 
{
    public:
    int minDeletionSize(vector<string>& strs) 
    {
        if (strs.empty()) return 0;

        int ROW = strs.size();
        int COL = strs[0].size();
        vector<vector<bool>> sorted(ROW-1, false);

        int minDeletion = 0;
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
                minDeletion++;
            } else {
                for (int r=0; r<ROW-1; r++) {
                    if (strs[r][c] < strs[r+1][c]) {
                        sorted[r] = true;
                    }
                }
            }
        }
        return minDeletion;
    }
};