class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        self.DIGITS_TO_CHARS = {
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
        curr_path = []
        self.dfs(0, curr_path, digits)
        return self.res


    def dfs(self, curr_idx, curr_path, digits):
        if not digits:
            return

        if curr_idx == len(digits):
            self.res.append("".join(curr_path))
            return
        
        for letter in self.DIGITS_TO_CHARS[digits[curr_idx]]:
            curr_path.append(letter)
            self.dfs(curr_idx+1, curr_path, digits)
            curr_path.pop()
        

