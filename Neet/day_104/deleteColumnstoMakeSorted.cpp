






// c b a
// d a f
// g h i

class Solution 
{
    public:
    int minDeletionSize(vector<string>& strs) 
    {
        if (strs.empty()) return 0;

        int ROW = strs.size();
        int COL = strs[0].size();

        int deleteCount = 0;
        int col = 0;
        while (col < COL) {
            for (int r=0; r<ROW; r++) {
                if (r-1 >= 0 && strs[r][col] < strs[r-1][col]) {
                    deleteCount++;
                    break;
                }
            }
            col++;
        }
        return deleteCount;
    }
};