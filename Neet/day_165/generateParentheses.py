


class Solution(object):
    def generateParenthesis(self, n):
        self.res = []
        self.dfs(0, 0, "", n)
        return self.res

    def dfs(self, numOpen, numClose, currPath, n):
        if numOpen == n and numClose == n:
            self.res.append(currPath)
            return

        if numClose < numOpen:
            currPath += ')'
            self.dfs(numOpen, numClose+1, currPath, n)
            currPath = currPath[:-1]

        if numOpen < n:
            currPath += '('
            self.dfs(numOpen+1, numClose, currPath, n)
            currPath = currPath[:-1]
            



        