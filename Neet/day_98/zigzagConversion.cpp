class Solution 
{
    public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1 || s.length() <= numRows) return s;
        if (numRows == 0 || s.length() == 0) return "";

        int groupSize = numRows + numRows - 2;
        int colPerGroup = 1 + numRows - 2;
        int numOfGroups = (s.length() + groupSize - 1) / groupSize;
        int numCols = numOfGroups * colPerGroup;

        // assign the grid
        vector<vector<char>> grid(numRows, vector<char>(numCols, '#'));

        int idx = 0, col = 0;
        while (idx < s.length()) {
            // go down the col
            for (int row=0; row<numRows && idx < s.length(); row++) {
                grid[row][col] = s[idx];
                idx++;
            }
            col++;

            // go up right
            for (int row = numRows-2; row>0 && idx < s.length(); row--) {
                grid[row][col] = s[idx];
                idx++;
                col++;
            }
        }

        // read grid and build res
        string res = "";
        for (int r=0; r<numRows; r++) {
            for (int c=0; c<numCols; c++) {
                if (grid[r][c] != '#') {
                    res += grid[r][c];
                }
            }
        }
        return res;
    }
};
        