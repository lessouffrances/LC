class Solution 
{
    public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1) return s;
        int groupSize = numRows + numRows - 2;

        // ceiling division on numOfGroups
        int numOfGroups = (s.length() + groupSize - 1) / groupSize;
        // except for the first col, each char will occupy a col
        int colsPerGroup = 1 + (groupSize - numRows);
        int numCols = numOfGroups * colsPerGroup;

        vector<vector<char>> grid(numRows, vector<char>(numCols, '#'));
        // populate the grid
        int idx = 0;
        int col = 0;
        while (idx < s.length()) {
            // go down to the bottom row
            for (int r=0; r<numRows && idx<s.length(); r++) {
                grid[r][col] = s[idx];
                idx++;
            }
            col++;

            // go up right
            for (int r=numRows-2; r>=1 && idx<s.length(); r--) {
                grid[r][col] = s[idx];
                idx++;
                col++;
            }
        }

        // read the grid
        string res = "";
        for (int r=0; r<numRows; r++) {
            for (int c=0; c<numCols; c++) {
                if (grid[r][c] != '#') res += grid[r][c];
            }
        }
        return res;
    }
};