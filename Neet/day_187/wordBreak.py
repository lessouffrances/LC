class Solution(object):
    def wordBreak(self, s, wordDict):
        if not s or not wordDict: return False
        self.word_set = set(wordDict)
        self.memo = {}

        return self.dfs(0, s)

    def dfs(self, curr_idx, s):
        if curr_idx == len(s):
            return True

        if curr_idx in self.memo: return self.memo[curr_idx]

        for word in self.word_set:
            if s[curr_idx : curr_idx+len(word) ] != word: continue
            if self.dfs(curr_idx+len(word), s): 
                self.memo[curr_idx] = True
                return True
        self.memo[curr_idx] = False
        return False

    
