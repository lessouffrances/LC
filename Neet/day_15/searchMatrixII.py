class Solution:
    def searchMatrix(self, matrix, target) -> bool:
        flatedList = [ num for row in matrix for num in row]
        print(flatedList)
        return True if target in flatedList else False



def main():
    self = Solution
    matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
    target = 90
    Solution.searchMatrix(self, matrix, target)
main()