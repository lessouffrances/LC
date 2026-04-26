class Solution(object):
    def letterCombinations(self, digits):
        if not digits: 
            return
        
        self.digit_to_chars = {
            '2': ['a','b','c'],
            '3': ['d','e','f'],
            '4': ['g','h','i'],
            '5': ['j','k','l'],
            '6': ['m','n','o'],
            '7': ['p','q','r','s'],
            '8': ['t','u','v'],
            '9': ['w','x','y','z']
        }
        self.res = []
        self.dfs(digits, 0, "")
        return self.res


    def dfs(self, digits, currIdx, currPath):
        if currIdx == len(digits):
            self.res.append(currPath)
            return

        for ch in self.digit_to_chars[digits[currIdx]]:
            currPath += ch
            self.dfs(digits, currIdx+1, currPath)
            currPath = currPath[:-1]
        