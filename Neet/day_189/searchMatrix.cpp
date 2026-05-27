class Solution 
{
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.empty()) return false;
        int ROW = matrix.size();
        int COL = matrix[0].size();

        int left = 0;
        int right = ROW*COL-1;

        while (left <= right) {
            int mid = left + (right-left)/2;
            int r = mid / COL;
            int c = mid % COL;

            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return false;
    }
};