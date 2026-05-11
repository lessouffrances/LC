class Solution(object):
    def numIslands(self, grid):
        if not grid:
            return 0
        self.ROW = len(grid)
        self.COL = len(grid[0])
        self.DIRS = [ [0,1],[0,-1],[1,0],[-1,0] ]
        
        num_of_islands = 0
        for r in range(self.ROW):
            for c in range(self.COL):
                if grid[r][c] == '1':
                    num_of_islands += 1
                    self.dfs(r, c, grid)
        return num_of_islands

    def dfs(self, row, col, grid):
        grid[row][col] = '2'

        for DIR in self.DIRS:
            new_r = DIR[0] + row
            new_c = DIR[1] + col

            if new_r<0 or new_r>=self.ROW or new_c<0 or new_c>=self.COL:
                continue
            if grid[new_r][new_c] != '1':
                continue

            self.dfs(new_r, new_c, grid)



        
