class Solution 
{
    public:
    vector<vector<int>> generateMatrix(int n) 
    {
        if (n <= 0) return {};

        // alloc a n*n matrix
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top = 0, bottom = n-1;
        int left = 0, right = n-1;

        int val = 1;
        while (top <= bottom && left <= right) {
            // fill top row
            for (int c=left; c<=right; c++) {
                matrix[top][c] = val++;
            }
            top++;

            // fill right col
            for (int r=top; r<=bottom; r++) {
                matrix[r][right] = val++;
            }
            right--;

            if (top > bottom || left > right) break;

            // fill bottom row
            for (int c=right; c>=left; c--) {
                matrix[bottom][c] = val++;
            }
            bottom--;

            // fill left col
            for (int r=bottom; r>=top; r--) {
                matrix[r][left] = val++;
            }
            left++;
        }
        return matrix;
    }
};