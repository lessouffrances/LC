class Solution:
    def solve(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # iterate thru the grid, if (border and 'O'): dfs on it and change the path into 'T'
        #                        if '0': change it to 'X'

        # only used for border 'O's
        def capture(row, col):
            # base case when index out of border and element not being 'O'
            if (row < 0 or col < 0 or 
            row == len(board) or col == len(board[0]) or board[row][col] != 'O'): return

            board[row][col] = 'T'

            capture(row+1, col)
            capture(row-1, col)
            capture(row, col+1)
            capture(row, col-1)
            
        for r in range(len(board)):
            for c in range(len(board[0])):
                if (r in [0, len(board)-1] or c in [0, len(board[0])-1]) and board[r][c] == 'O':
                    capture(r, c)

        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == 'O':
                    board[r][c] = 'X'

         # iterate thru the grid and change the 'T's back to 'O's
        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == 'T':
                    board[r][c] = 'O'


def main():
    solution = Solution()
    board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    # output = [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
    solution.solve(board)
main()