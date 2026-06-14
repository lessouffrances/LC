class Solution(object):
    def letterCombinations(self, digits):
        if not digits: return []
        self.phone_map = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        self.res = [] # list of string
        self.dfs(0, [], digits)
        return self.res


    def dfs(self, curr_idx, curr_path, digits):
        if curr_idx == len(digits):
            self.res.append("".join(curr_path))
            return
        
        for ch in self.phone_map[digits[curr_idx]]:
            curr_path.append(ch)
            self.dfs(curr_idx+1, curr_path, digits)
            curr_path.pop()

