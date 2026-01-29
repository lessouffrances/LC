class Solution 
{
    public:
    int minDeletionSize(vector<string>& strs) 
    {
        if (strs.empty() || strs[0].empty()) return 0;

        int ROW = strs.size();
        int COL = strs[0].size();
        int deleteCount = 0;

        for (int col=0; col<COL; col++) {
            // check if the col is sorted
            for (int row=1; row<ROW; row++) {
                if (strs[row][col] < strs[row-1][col]) {
                    deleteCount++;
                    break;
                }
            }
        }
        return deleteCount;
    }
};