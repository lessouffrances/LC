class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if not s:
            return 0

        window_metric = [0] * 128
        left = 0
        max_len = 0

        for right in range(len(s)):
            window_metric[ord(s[right])] += 1
            while window_metric[ord(s[right])] == 2:
                window_metric[ord(s[left])] -= 1
                left += 1

            max_len = max(max_len, right - left + 1)
        return max_len
       
        