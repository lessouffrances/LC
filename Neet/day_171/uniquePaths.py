class Solution(object):
    def uniquePaths(self, m, n):
        if m == 0 or n == 0: 
            return 0

        grid = [ [0 for _ in range(n)] for _ in range(m) ]
        for c in range(n):
            grid[0][c] = 1
        for r in range(m):
            grid[r][0] = 1

        for r in range(1, m):
            for c in range(1, n):
                grid[r][c] = grid[r-1][c] + grid[r][c-1]
        
        return grid[m-1][n-1]

        