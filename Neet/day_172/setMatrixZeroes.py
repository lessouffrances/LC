class Solution(object):
    def setZeroes(self, matrix):
        ROW = len(matrix)
        COL = len(matrix[0])

        is_first_row_zero = False
        is_first_col_zero = False

        for r in range(ROW):
            if matrix[r][0] == 0:
                is_first_col_zero = True
                break
        
        for c in range(COL):
            if matrix[0][c] == 0:
                is_first_row_zero = True
                break
        
        # use the first row and col as markers
        for r in range(1, ROW):
            for c in range(1, COL):
                if matrix[r][c] == 0:
                    matrix[r][0] = 0
                    matrix[0][c] = 0

        # realize the marker
        for r in range(1, ROW):
            if matrix[r][0] == 0:
                for c in range(COL):
                    matrix[r][c] = 0
        
        for c in range(1, COL):
            if matrix[0][c] == 0:
                for r in range(ROW):
                    matrix[r][c] = 0

        # realize the flags
        if is_first_row_zero:
            for c in range(COL):
                matrix[0][c] = 0
        
        if is_first_col_zero:
            for r in range(ROW):
                matrix[r][0] = 0
        

        

        