class Solution(object):
    def largestMagicSquare(self, grid):
        if not grid:
            return 0

        ROW = len(grid)
        COL = len(grid[0])

        # it is important to go from large to small
        for k in range(min(ROW, COL), 0, -1):
            for r in range(ROW-k+1):
                for c in range(COL-k+1):
                    if self.isMagicSquare(r, c, k, grid):
                        return k
        return 1

    def isMagicSquare(self, row, col, k, grid):
        # benchmark sum
        benchmark = 0
        for r in range(row, row+k):
            benchmark += grid[r][col]
        
        # check all rows
        for r in range(row, row+k):
            row_sum = 0
            for c in range(col, col+k):
                row_sum += grid[r][c]
            if row_sum != benchmark: return False
        
        # check all cols
        for c in range(col, col+k):
            col_sum = 0
            for r in range(row, row+k):
                col_sum += grid[r][c]
            if col_sum != benchmark: return False

        # check all diags 
        diag1, diag2 = 0, 0
        for i in range(k):
            diag1 += grid[row+i][col+i]
            diag2 += grid[row+i][col+k-i-1]
        if diag1 != benchmark or diag2 != benchmark:
            return False
        return True
        