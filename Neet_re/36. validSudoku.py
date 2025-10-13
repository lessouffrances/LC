class Solution:
    def isValidSudoku(self, board) -> bool:
        # get rid of all the string types if number
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] != ".":
                    board[i][j] = int(board[i][j])

        print(self.rowColLookUp("row", len(board), len(board[0]), board))
        print(self.rowColLookUp("col", len(board), len(board[0]), board))
        print(self.blockLookUp_2(9, 9, 3, board))
        return (self.rowColLookUp("row", len(board), len(board[0]), board) == True) and (self.rowColLookUp("col", len(board), len(board[0]), board) == True) and (self.blockLookUp_2(9, 9, 3, board) == True)

         
    def rowColLookUp(self, sequence, row, col, board):
        for i in range(row):
            seenSet = set()
            for j in range(col):
                if sequence == "row" and board[i][j] != ".":
                    print(board[i][j])
                    if board[i][j] in seenSet:
                        return False
                    else:
                        seenSet.add(board[i][j])

                elif sequence == "col" and board[j][i] != ".":
                    print(board[j][i])
                    if board[j][i] in seenSet:
                        return False
                    else:
                        seenSet.add(board[j][i])
            seenSet.clear
        return True
        
    def blockLookUp_2(self, totalRow, totalCol, blockSize, board):
        for blockStartRow in range(0, totalRow, blockSize):
            for blockStartCol in range(0, totalCol, blockSize):
                print(f"\nBlock starting at ({blockStartRow}, {blockStartCol}):")
                seenSet = set()
                for row in range(blockStartRow, blockStartRow + blockSize):
                    for col in range(blockStartCol, blockStartCol + blockSize):
                        print(board[row][col], end=" ")
                        if board[row][col] in seenSet and board[row][col] != ".":
                            return False
                        elif board[row][col] != ".":
                            seenSet.add(board[row][col])

                        print()  # Move to the next row in the block
        return True
    

    
    def blockLookUp_1(self, startRow, endRow, startCol, endCol, board):
        for i in range(startRow, endRow):
            for j in range(startCol, endCol):
                seenSet = set()
                if board[i][j] in seenSet:
                    return False
                else:
                    seenSet.add(board[i][j])
                    continue
            seenSet.clear()

def main():
    self = Solution()
    board = [["5","3",".",".","7",".",".",".","."]
             ,["6",".",".","1","9","5",".",".","."]
             ,[".","9","8",".",".",".",".","6","."]
             ,["8",".",".",".","6",".",".",".","3"]
             ,["4",".",".","8",".","3",".",".","1"]
             ,["7",".",".",".","2",".",".",".","6"]
             ,[".","6",".",".",".",".","2","8","."]
             ,[".",".",".","4","1","9",".",".","5"]
             ,[".",".",".",".","8",".",".","7","9"]]
    
    board = [[".",".",".",".",".",".",".",".","."],
             [".",".",".",".",".",".",".",".","."],
             [".","9",".",".",".",".",".",".","1"],
             ["8",".",".",".",".",".",".",".","."],
             [".","9","9","3","5","7",".",".","."],
             [".",".",".",".",".",".",".","4","."],
             [".",".",".","8",".",".",".",".","."],
             [".","1",".",".",".",".","4",".","9"],
             [".",".",".","5",".","4",".",".","."]]
    
    
    
    print(Solution.isValidSudoku(self, board))
main()