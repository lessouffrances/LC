class Solution(object):
    def characterReplacement(self, s, k):
        if not s: return 0
        max_len = 0
        max_freq = 0
        window_freq = {}
        left = 0
        n = len(s)

        for right in range(n): 
            window_freq[s[right]] = window_freq.get(s[right], 0)+1
            max_freq = max(max_freq, window_freq[s[right]])

            while right-left+1-max_freq > k:
                if s[left] in window_freq:
                    window_freq[s[left]] -= 1
                    if window_freq[s[left]] == 0:
                        del window_freq[s[left]]
                    left += 1
            
            max_len = max(max_len, right-left+1)
        
        return max_len


        