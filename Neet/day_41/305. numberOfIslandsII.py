class Solution:
    def numIslands2(self, m, n, positions):
        land = [ [0 for _ in range(n)] for _ in range(m) ]
        for row in land:
            print(row, end="\n")
        print("\n\n")

        for position in positions:
            row, col = position[0], position[1]
            land[row][col] = 1
        
        for row in land:
            print(row, end="\n")
        print("\n\n")
        
        row_set, col_set = set([-2]), set([-2])
        islands = []
        island = 0

        for row in range(len(land)):
            for col in range(len(land[0])):
                if land[row][col] == 1:
                    if abs(row - max(row_set)) >= 1 and abs(col - max(col_set)) >= 1: 
                        island += 1
                    if abs(row - max(row_set)) >= 1 and abs(col - max(col_set)) >= 1: 
                        island += 1
                        print(f"Add {row}{col}.")
                    row_set.add(row)
                    col_set.add(col)
                    islands.append(island)
                    print(f"the current row set is: {row_set}, col_set is {col_set}")
        print(islands)


def main():
    solution = Solution()
    m = 3
    n = 3
    positions = [[0,0],[0,1],[1,2],[2,1]] # [1, 1, 2, 3]
    m = 1
    n = 1
    positions = [[0,0]] # [1]
    m = 2
    n = 2
    positions = [[0,0],[1,1],[0,1]] # [1, 2, 1] 
    solution.numIslands2(m, n, positions)
main()