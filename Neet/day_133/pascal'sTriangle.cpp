
// Time: O(N ^ 2)  :  (1+N)*N / 2
// Space: O(N ^ 2)

class Solution 
{
    public:
    vector<vector<int>> generate(int numRows) 
    {
        if (numRows == 0) return { {1} };
        // base case
        vector<vector<int>> triangle;
        triangle.push_back( {1} );

        for (int r=1; r<numRows; r++) {
            vector<int> row;
            for (int c=0; c<r+1; c++) {
                if (c == 0 || c == r) {
                    row.push_back(1);
                    continue;
                }
                row.push_back(triangle[r-1][c-1] + triangle[r-1][c]);
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};