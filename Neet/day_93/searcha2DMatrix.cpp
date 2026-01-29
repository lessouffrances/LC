class Solution 
{
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.empty()) return false;

        int ROW = matrix.size();
        int COL = matrix[0].size();

        int left = 0, right = ROW*COL - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // the way to retrieve the val on a 2D grid
            int row = mid / COL;
            int col = mid % COL;
            int midVal = matrix[row][col];

            if (midVal == target) return true;
            if (midVal > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return false;
    }
};