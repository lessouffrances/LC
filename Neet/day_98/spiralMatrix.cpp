class Solution 
{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return {};
        int ROW = matrix.size();
        int COL = matrix[0].size();

        int left = 0, right = COL-1;
        int top = 0, bottom = ROW-1;

        vector<int> res;
        while (top <= bottom && left <= right) {
            // top row
            for (int col=left; col<=right; col++) {
                res.push_back(matrix[top][col]);
            }
            top++;

            // right col
            for (int row=top; row<=bottom; row++) {
                res.push_back(matrix[row][right]);
            }
            right--;

            if (top > bottom || right < left) break;

            // bottom row
            for (int col=right; col>=left; col--) {
                res.push_back(matrix[bottom][col]);
            }
            bottom--;

            // left col
            for (int row=bottom; row>=top; row--) {
                res.push_back(matrix[row][left]);
            }
            left++;
        }

        return res;
    }
};