class Solution:
    def searchMatrix(self, matrix, target) -> bool:
        left, right = 0, len(matrix)-1

        while left <= right:
            mid = (left+right) // 2

            if target in matrix[mid]:
                return True
            elif matrix[mid][0] > target:
                right = mid-1
            elif matrix[mid][-1] < target:
                left = mid+1
            else:
                # Target is not in matrix[mid], but would be in this row if it existed
                # So target is not in matrix at all
                return False
            
        return False




def main():
    solution = Solution()
    # matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
    # target = 3 #true

    matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
    target = 13 #false
    print(solution.searchMatrix(matrix, target))
main()