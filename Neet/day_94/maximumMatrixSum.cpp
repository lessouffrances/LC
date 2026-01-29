class Solution {
    public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        long long totalSum = 0;
        int negativeCount = 0;
        int minAbsValue = INT_MAX;

        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                int val = matrix[r][c];
                totalSum += abs(val);
                if (val < 0) {
                    negativeCount++;
                }
                minAbsValue = min(minAbsValue, abs(val));
            }
        }

        if (negativeCount % 2 == 1) {
            totalSum -= 2 * minAbsValue;
        }
        return totalSum;
    }
};