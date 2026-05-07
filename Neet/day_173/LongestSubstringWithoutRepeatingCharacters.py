class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if not s:
            return

        n = len(s)
        window_counter = [0] * 128

        left = 0
        max_len = 0
        for right in range(n):
            window_counter[ord(s[right])] += 1
            while window_counter[ord(s[right])] == 2:
                window_counter[ord(s[left])] -= 1
                left += 1
            max_len = max(max_len, right - left + 1)
        return max_len
            
        