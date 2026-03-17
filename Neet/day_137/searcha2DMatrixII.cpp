


// Start from the top-right corner 
// — move left if too big, move down if too small.

// Time: O(ROW * COL)
// Space: O(1)
class Solution 
{
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();

        int r = 0, c = matrix[0].size()-1;
        while (r < matrix.size() && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};