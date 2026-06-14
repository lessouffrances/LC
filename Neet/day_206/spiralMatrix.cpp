class Solution 
{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return {};
        vector<int> res;
        int ROW = matrix.size();
        int COL = matrix[0].size();
        int top = 0, left = 0;
        int bottom = ROW-1, right = COL-1;

        while (top <= bottom && left <= right) {
            // top row
            for (int c=left; c<=right; c++) {
                res.push_back( matrix[top][c] );
            }
            top++;
            // right col
            for (int r=top; r<=bottom; r++) {
                res.push_back( matrix[r][right] );
            }
            right--;
            if (top > bottom || left > right) break;
            // bottom row
            for (int c=right; c>=left; c--) {
                res.push_back( matrix[bottom][c] );
            }
            bottom--;
            // left col
            for (int r=bottom; r>=top; r--) {
                res.push_back( matrix[r][left] );
            }
            left++;
        }

        return res;
    }
};