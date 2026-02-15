class Solution 
{
    public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        vector<vector<double>> glassAmounts(102); // 102 row

        for (int rowSize=1; rowSize<=102, rowSize++) {
            glassAmounts[rowSize-1].resize(rowSize, 0.0);
        }

        glassAmounts[0][0] = poured;

        for (int r=0; r<=query_row; r++) {
            for (int c=0; c<=r; c++) {
                double overflow = (glassAmounts[r][c] - 1.0) / 2;

                if (overflow > 0) {
                    glassAmounts[r][c] += overflow;
                    glassAmounts[r][c+1] += overflow; 
                }
            }
        }
        return min(1.0, glassAmounts[query_row][query_glass]);
    }
};