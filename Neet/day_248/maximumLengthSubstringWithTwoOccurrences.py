class Solution(object):
    def maximumLengthSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0: return 0

        n = len(s)
        window_counter = {} 
        left = 0
        max_len = 0

        for right in range(n):
            window_counter[s[right]] = window_counter.get(s[right], 0) + 1
            # while the window is invalid
            while window_counter[s[right]] == 3:
                window_counter[s[left]] -= 1
                if window_counter[s[left]] == 0:
                    del window_counter[s[left]]
                left += 1
            max_len = max(max_len, right-left+1)
        
        return max_len
            
