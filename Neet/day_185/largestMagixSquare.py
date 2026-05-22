#  T: O(M * N * k^3)
#  S: O(1)
class Solution(object):
    def largestMagicSquare(self, grid):
        if not grid:
            return 0
        self.ROW = len(grid)
        self.COL = len(grid[0])

        # iterate through each and every square
        # k from the maximized possible side to 2
        for k in range(min(self.ROW, self.COL), 1, -1):
            # r+k <= self.ROW
            for r in range(0, self.ROW-k+1):
                for c in range(0, self.COL-k+1):
                    if self.isMagicSquare(r, c, k, grid): return k
        return 1

    def isMagicSquare(self, row, col, k, grid):
        # benchmark sum
        # sum the first row in this square
        benchmark = 0
        for c in range(col, col+k):
            benchmark += grid[row][c]
        
        # check each row
        for r in range(row, row+k):
            row_sum = 0
            for c in range(col, col+k):
                row_sum += grid[r][c]
            if row_sum != benchmark: return False
        
        # check each col
        for c in range(col, col+k):
            col_sum = 0
            for r in range(row, row+k):
                col_sum += grid[r][c]
            if col_sum != benchmark: return False
        
        # check each diag
        diag1, diag2 = 0, 0
        for i in range(0, k):
            diag1 += grid[row+i][col+i]
            diag2 += grid[row+i][col+k-i-1]

        return diag1 == benchmark and diag2 == benchmark