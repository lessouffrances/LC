class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if not s:
            return 0

        left = 0
        n = len(s)
        metric = [0]*128
        max_len = 0
        for right in range(n):
            metric[ord(s[right])] += 1
            while metric[ord(s[right])] == 2:
                metric[ord(s[left])] -= 1
                left += 1
            max_len = max(max_len, right-left+1)
        
        return max_len
            