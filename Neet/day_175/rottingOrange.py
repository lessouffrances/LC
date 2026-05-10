from collections import deque

class Solution(object):
    def orangesRotting(self, grid):
        if not grid:
            return -1

        self.ROW = len(grid)
        self.COL = len(grid[0])
        self.DIRS = [ [0,1], [0,-1], [1,0], [-1,0] ]

        # push all rotting oranges onto q
        num_of_fresh_oranges = 0
        q = deque()
        for r in range(self.ROW):
            for c in range(self.COL):
                if grid[r][c] == 2:
                    q.append( (r, c) )
                elif grid[r][c] == 1:
                    num_of_fresh_oranges += 1
        minutes = 0
        while q:
            size = len(q)
            has_infected = False
            for _ in range(size):
                r, c = q[0]
                q.popleft()

                for DIR in self.DIRS:
                    new_r = r + DIR[0]
                    new_c = c + DIR[1]
                    if new_r<0 or new_r >= self.ROW or new_c<0 or new_c >= self.COL:
                        continue
                    if grid[new_r][new_c] != 1:
                        continue

                    has_infected = True
                    num_of_fresh_oranges -= 1
                    grid[new_r][new_c] = 2
                    q.append( (new_r, new_c) )
                
            if has_infected:
                minutes += 1

        if num_of_fresh_oranges == 0:
            return minutes
        return -1
                    

            
