class Solution(object):
    def rotate(self, matrix):
        ROW = len(matrix)
        COL = len(matrix[0])

        for r in range(ROW):
            for c in range(r+1, COL):
                temp = matrix[r][c]
                matrix[r][c] = matrix[c][r]
                matrix[c][r] = temp

        for row in matrix:
            row[:] = row[::-1]