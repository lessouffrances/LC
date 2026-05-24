class Solution(object):
    def rotate(self, matrix):
        if not matrix: return
        n = len(matrix)

        # inverse
        for r in range(n):
            for c in range(r+1, n):
                if r == c: continue
                matrix[r][c], matrix[c][r] = matrix[c][r], matrix[r][c]
        for row in matrix:
            row = row[::-1]
    