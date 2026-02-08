




class Solution 
{
    public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return 0;

        int ROW = matrix.size();
        int COL = matrix[0].size();
        int negativeCount = 0;
        int minAbsValue = INT_MAX;
        long long totalSum = 0;

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (matrix[r][c] < 0) {
                    negativeCount++;
                }
                totalSum += abs(matrix[r][c]);
                minAbsValue = min(minAbsValue, abs(matrix[r][c]));
            }
        }

        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsValue;
        } 
        
        return totalSum;
    }
};