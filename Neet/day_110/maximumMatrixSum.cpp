






// only even counts of negatives can be all positive 
// if the num of negatives are odd, choose the one with min abs


class Solution 
{
    public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();

        int negativeCount = 0;
        int minAbsVal = INT_MAX;
        long long totalSum = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (matrix[r][c] < 0) {
                    negativeCount++;
                }
                minAbsVal = min(minAbsVal, abs(matrix[r][c]));
                totalSum += abs(matrix[r][c]);
            }
        }

        if (negativeCount % 2 == 0) return totalSum;

        totalSum -= 2 * minAbsVal;
        return totalSum;
    }
};