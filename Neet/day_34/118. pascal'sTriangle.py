class Solution:
    def generate(self, numRows):
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]

        res = [ [] for _ in range(numRows) ]
        res[0] = [1]

        for row in range(1, numRows):
            for col in range(row+1):
                if (col-1) < 0 or col > len(res[row-1])-1:
                    res[row].append(1)
                else:
                    res[row].append(res[row-1][col-1] + res[row-1][col])
        return res


def main():
    solution = Solution()
    numRows = 5  #[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    solution.generate(numRows)
main()
