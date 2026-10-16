class Solution 
{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        int ROW = matrix.size();
        int COL = matrix[0].size();

        int top = 0, bottom = ROW-1;
        int left = 0, right = COL-1;

        vector<int> res;
        while (top <= bottom && left <= right)
        {
            for (int c=left; c<=right; c++) {
                res.push_back(matrix[top][c]);
            }
            top++;

            for (int r=top; r<=bottom; r++) {
                res.push_back(matrix[r][right]);
            }
            right--;

            if (top > bottom || left > right) break;

            for (int c=right; c>=left; c--) {
                res.push_back(matrix[bottom][c]);
            }
            bottom--;

            for (int r=bottom; r>=top; r--) {
                res.push_back(matrix[r][left]);
            }
            left++;
        }
        return res;
    }
};