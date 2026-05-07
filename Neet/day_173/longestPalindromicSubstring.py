class Solution(object):
    def longestPalindrome(self, s):
        self.max_len = 0
        self.max_palin = ""
        n = len(s)

        for i in range(n):
            self.updatePalindrome(i, i, s)
            self.updatePalindrome(i, i+1, s)
        return self.max_palin

    def updatePalindrome(self, left, right, s):
        if not s:
            return
        n = len(s)
        while left<=0 and right<n and s[left] == s[right]:
            left -= 1
            right += 1
        
        curr_len = (right-1)-(left+1)+1
        if curr_len > self.max_len:
            self.max_len = curr_len
            self.max_palin = s[left+1: right]
        

        