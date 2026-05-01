class Solution(object):
    def exist(self, board, word):
        self.ROW = len(board)
        self.COL = len(board[0])
        self.DIRS = [(-1,0), (1,0), (0,1), (0,-1)]

        for r in range(self.ROW):
            for c in range(self.COL):
                if board[r][c] == word[0]:
                    original = board[r][c]
                    board[r][c] = '#'
                    if self.dfs(r, c, 1, board, word): return True
                    board[r][c] = original
        return False

    def dfs(self, row, col, curr_idx, board, word):
        # base case
        if curr_idx == len(word):
            return True
        
        for DIR in self.DIRS:
            new_r = row + DIR[0]
            new_c = col + DIR[1]
            
            # invalid
            if new_r < 0 or new_r >= self.ROW or new_c < 0 or new_c >= self.COL: continue
            if word[curr_idx] != board[new_r][new_c]: continue

            original = board[new_r][new_c]
            board[new_r][new_c] = '#'
            if self.dfs(new_r, new_c, curr_idx+1, board, word): return True
            board[new_r][new_c] = original
        return False






        
