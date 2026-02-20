class NumMatrix 
{
    public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        matrix = matrix;
    }
    void update(int row, int col, int val) 
    {
        matrix[row][col] = val;
    }
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int sum = 0;
        for (int r=row1; r<=row2; r++) {
            for (int c=col1; c<=col2; c++) {
                sum += matrix[r][c];
            }
        }
        return sum;
    }
    private:
    vector<vector<int>>& matrix;
};
    
   