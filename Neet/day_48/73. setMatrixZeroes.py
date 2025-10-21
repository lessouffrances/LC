class Solution:
    def setZeroes(self, matrix):


        def setZeroesHelper(row, col):
            for c in range(len(matrix[0])):
                matrix[row][c] = 0 
            for r in range(len(matrix)):
                matrix[r][col] = 0 

        waitlist = []
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if matrix[r][c] == 0:
                    print(f"{r}, {c}, {matrix[r][c]} identified!")
                    waitlist.append([r, c])
                else:
                    continue

        for coordinates in waitlist:
            setZeroesHelper(coordinates[0], coordinates[1])
        for row in matrix:
            print(row, end='\n')
        print('\n\n')
                    

def main():
    solution = Solution()
    matrix = [[1,1,1],[1,0,1],[1,1,1]]
    #[[1,0,1],[0,0,0],[1,0,1]]
    # matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    #[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
    solution.setZeroes(matrix)
main()