import random
# import numpy
class Solution:
    def divideIntoBlocks(self, matrix, blockSize):
        blocks = []
        rows, cols = len(matrix), len(matrix[0])
        for i in range(0, rows, blockSize[0]):
            for j in range(0, cols, blockSize[1]):
                block = [ row[j: j+blockSize[1]] for row in matrix[i: i+blockSize[0]] ]
                blocks.append(block)
        
        return blocks
    
    def rebuildFromBlocks(self, blocks, matrix, blockSize):
        # newMatrix = np.zeros(matrix, dtype=int)
        newMatrix = [ [0 for num in row ] for row in matrix ]
        rows = len(newMatrix)
        cols = len(newMatrix[0])
        index = 0

        for i in range(0, rows, blockSize[0]):
            for j in range(0, cols, blockSize[1]):
                block = blocks[index]
                for bi in range(blockSize[0]):
                    newMatrix[i+bi][j:j+blockSize[1]] = block[bi]
                index += 1
        return newMatrix

def main():
    self = Solution
    matrix = [
    [1, 2, 3, 4, 5, 6],
    [7, 8, 9, 10, 11, 12],
    [13, 14, 15, 16, 17, 18],
    [19, 20, 21, 22, 23, 24],
    [25, 26, 27, 28, 29, 30],
    [31, 32, 33, 34, 35, 36]
    ]

    blockSize = [3, 3]
    blocks = self.divideIntoBlocks(self, matrix, blockSize)
    random.shuffle(blocks)
    print(self.rebuildFromBlocks(self, blocks, matrix, blockSize))
main()