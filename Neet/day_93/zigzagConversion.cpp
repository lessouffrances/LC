class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1 || s.length() <= numRows) return s;  // !!! Edge cases
        if (numRows == 0 || s.length() == 0) return "";
        
        int groupSize = numRows + (numRows - 2);  // Full zigzag cycle
        int colPerGroup = 1 + (numRows - 2);
        int numGroups = (s.length() + groupSize - 1) / groupSize;  // Ceiling division
        int numCols = numGroups * colPerGroup;

        vector<vector<char>> grid(numRows, vector<char>(numCols, '#'));

        int idx = 0;
        int col = 0;
        
        while (idx < s.length()) {
            // Go down the column
            for (int row = 0; row < numRows && idx < s.length(); row++) {
                grid[row][col] = s[idx];
                idx++;
            }
            col++;
            
            // Go up diagonally
            for (int row = numRows - 2; row > 0 && idx < s.length(); row--) {
                grid[row][col] = s[idx];
                idx++;
                col++;
            }
        }
        
        // Read row by row to build result
        string result = "";
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < numCols; c++) {
                if (grid[r][c] != '#') {
                    result += grid[r][c];
                }
            }
        }
        
        return result;
    }
};