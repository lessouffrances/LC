class Solution(object):
    def numIslands(self, grid):
        self.ROW = len(grid)
        self.COL = len(grid[0])
        self.DIRS = [[0,1], [0,-1], [1,0], [-1,0]]
        res = 0
        for r in range(self.ROW):
            for c in range(self.COL):
                if grid[r][c] == '1':
                    self.dfs(r, c, grid)
                    res += 1
        return res

    def dfs(self, r, c, grid):
        grid[r][c] = '2'

        for DIR in self.DIRS:
            new_r = r + DIR[0]
            new_c = c + DIR[1]

            if new_r<0 or new_r>=self.ROW or new_c<0 or new_c>=self.COL: continue
            if grid[new_r][new_c] != '1': continue
            self.dfs(new_r, new_c, grid)