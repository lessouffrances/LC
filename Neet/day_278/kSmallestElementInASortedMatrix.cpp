class Solution 
{
    public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        N = matrix.size();
        int start = matrix[0][0], end = matrix[N-1][N-1];

        while (start < end) {
            int mid = start + (end - start) / 2;
            vector<int> smallLargePair = {matrix[0][0], matrix[N-1][N-1]};

            int count = countLessEqual(matrix, mid, smallLargePair);

            if (count == k) {
                return smallLargePair[0];
            }

            if (count < k) {
                start = smallLargePair[1]; // search higher
            } else {
                end = smallLargePair[0]; // search lower
            }
        }
        return start;
    }

    private:
    int N;

    int countLessEqual(vector<vector<int>>& matrix, int mid, vector<int>& smallLargePair)
    {
        int count = 0;
        int row = N-1, col = 0;

        while (row >= 0 && col < N) {
            if (matrix[row][col] > mid) {
                // matrix[row][col] is bigger than mid; track the smallest number greater than mid
                if (matrix[row][col] < smallLargePair[1]) {
                    smallLargePair[1] = matrix[row][col];
                }
                row--;
            } else {
                // matrix[row][col] is <= mid; track the biggest number <= mid
                if (matrix[row][col] > smallLargePair[0]) {
                    smallLargePair[0] = matrix[row][col];
                }
                count += row + 1;
                col++;
            }
        }

        return count;
    }
};