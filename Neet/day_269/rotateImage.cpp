

// [1,2,3]
// [4,5,6]
// [7,8,9]
//   
// [1,4,7]
// [2,5,8]
// [3,6,9]

class Solution 
{
    public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for (int r=0; r<n; r++) {
            for (int c=r+1; c<n; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};