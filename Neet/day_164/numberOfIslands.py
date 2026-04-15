class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        self.ROW = len(grid)
        self.COL = len(grid[0])
        self.DIRS = [[0,1], [0,-1], [1,0], [-1,0]]

        number_of_islands = 0
        for r in range(self.ROW):
            for c in range(self.COL):
                if grid[r][c] == '1':
                    self.dfs(r, c, grid)
                    number_of_islands += 1
        return number_of_islands

    def dfs(self, row, col, grid: List[List[str]]) -> None:
        # mark visited
        grid[row][col] = '2'
        
        for dir in self.DIRS:
            new_r = row + dir[0]
            new_c = col + dir[1]

            if new_r < 0 or new_r >= self.ROW or new_c < 0 or new_c>=self.COL:
                continue
            if grid[new_r][new_c] != '1':
                continue

            self.dfs(new_r, new_c, grid)



        




