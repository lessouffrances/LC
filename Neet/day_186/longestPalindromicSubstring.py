class Solution(object):
    def longestPalindrome(self, s):
        self.palindrome = ""
        self.max_len = 0
        n = len(s)

        for i in range(n):
            self.updatePalindrome(i, i, s)
            self.updatePalindrome(i, i+1, s)
        return self.palindrome

    def updatePalindrome(self, left, right, s):
        n = len(s)

        while left >= 0 and right < n and s[left] == s[right]:
            left -= 1
            right += 1

        curr_len = (right-1)-(left+1)+1

        if curr_len > self.max_len:
            self.max_len = curr_len
            self.palindrome = s[left+1 : right]

        