class Solution:
    def searchMatrix(self, matrix, target):
        flatedList = [ num for row in matrix for num in row]
        print(flatedList)
        return True if target in flatedList else False

def main():
    self = Solution
    matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
    target = 90
    Solution.searchMatrix(self, matrix, target)
main()