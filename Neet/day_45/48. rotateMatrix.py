class Solution:
    def rotate(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix[0])
        
        content = []
        for row in range(n):
            for col in range(n):
                content.append(matrix[row][col])
        print(content)

        # fill in col by col from the last col of the matrix
        index = 0
        for col in range(n-1, -1, -1):
            for row in range(n):
                print(f"Filling ({row}, {col}) position.")
                print(content[index])
                matrix[row][col] = content[index]
                index += 1
        
        for row in matrix:
            print(row, end="\n")


def main():
    solution = Solution()
    # matrix = [[1,2,3],[4,5,6],[7,8,9]] #[[7,4,1],[8,5,2],[9,6,3]]
    matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]] #[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
    solution.rotate(matrix)
main()