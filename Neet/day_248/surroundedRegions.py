class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        if len(board) == 0: return
        self.ROW = len(board)
        self.COL = len(board[0])
        self.DIRS = [ [0,1], [0,-1], [-1,0], [1,0] ]
        self.visited = [ [ False for _ in range(self.COL)] for _ in range(self.ROW) ]

        # loop thru the border and dfs if O
        # left and right col
        for r in range(self.ROW):
            if board[r][0] == 'O':
                self.dfs(r, 0, board)
            if board[r][self.COL-1] == 'O':
                self.dfs(r, self.COL-1, board)
        # top and bottom row
        for c in range(self.COL):
            if board[0][c] == 'O':
                self.dfs(0, c, board)
            if board[self.ROW-1][c] == 'O':
                self.dfs(self.ROW-1, c, board) 
        
        # loop thru the board and make those Os to Xs
        # make Ts to Os
        for r in range(self.ROW):
            for c in range(self.COL):
                if board[r][c] == 'O':
                    board[r][c] = 'X'
                if board[r][c] == 'T':
                    board[r][c] = 'O'

    def dfs(self, row, col, board):
        self.visited[row][col] = True
        # if the Os are connected to the border, make them T
        board[row][col] = 'T'

        for DIR in self.DIRS:
            new_r = row + DIR[0]
            new_c = col + DIR[1]

            if new_r<0 or new_r>=self.ROW or new_c<0 or new_c>=self.COL: continue
            if self.visited[new_r][new_c]: continue
            if board[new_r][new_c] != 'O': continue

            # recurse
            self.dfs(new_r, new_c, board)




        