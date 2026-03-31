


// Time: O(ROW * COL)
// Space: O(1)
class Solution 
{
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();

        int r = 0, c = matrix[0].size()-1; // top-right corner
        // because smaller and large will have its dir

        while (r<ROW && c >= 0) {
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