class Solution:
    def shiftGrid(self, grid: list[list[int]], k: int):
        myList = []
        for lst in grid:
            for num in lst:
                myList.append(num)
        print(myList)
        k = k % (len(myList))

        lst = myList[len(myList) - k :] + myList[: len(myList) - k]
        print(lst)

        m = len(grid[0]) #col = 4

        n = 1
        while n < len(grid[0]):
            for i in range(len(grid)):
                grid[i] = lst[(n-1)*m : n*m]
            n += 1

        print(grid)
        return grid

        
def main():
    self = Solution()
    # grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]
    grid = [[1,2,3],[4,5,6],[7,8,9]]
    grid = [[1],[2],[3],[4],[7],[6],[5]]
    k = 23
    
    Solution.shiftGrid(self, grid, k)
    
main()