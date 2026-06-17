class Solution 
{
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.empty()) return false;

        int ROW = matrix.size();
        int COL = matrix[0].size();

        // start from the top-right corner
        int r = 0, c = COL-1;
        while (r<ROW && c>=0) {
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] > target) {
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};