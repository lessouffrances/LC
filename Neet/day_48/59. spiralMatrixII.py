class Solution:
    def generateMatrix(self, n):
        matrix = [ [0 for _ in range(n)] for _ in range(n) ]

        left, right = 0, n-1
        top, bottom = 0, n-1
        val = 1

        while left<=right:
            # fill in the top row 
            for c in range(left, right+1):
                matrix[top][c] = val
                val += 1
            top += 1

            # fill in thr right col
            for r in range(top, bottom+1):
                matrix[r][right] = val
                val += 1
            right -= 1

            # fill in the bottom row (reverse)
            for c in range(right, left-1, -1):
                matrix[bottom][c] = val
                val += 1
            bottom -= 1

            # fill in the left col (reverse)
            for r in range(bottom, top-1, -1):
                matrix[r][left] = val
                val += 1
            left += 1    
        
        for row in matrix:
            print(row, end='\n')
        print('\n\n')
    
def main():
    solution = Solution()
    n = 3 #[[1,2,3],[8,9,4],[7,6,5]]
    # n = 1 #[[1]]
    solution.generateMatrix(n)
main()