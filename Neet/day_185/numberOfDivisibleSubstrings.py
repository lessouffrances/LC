# T: O(N)
# S: O(N)

class Solution(object):
    def countDivisibleSubstrings(self, word):
        if not word:
            return 0
            
        ch_to_vals = {
            'a': 1, 'b': 1,
            'c': 2, 'd': 2, 'e': 2,
            'f': 3, 'g': 3, 'h': 3,
            'i': 4, 'j': 4, 'k': 4,
            'l': 5, 'm': 5, 'n': 5,
            'o': 6, 'p': 6, 'q': 6,
            'r': 7, 's': 7, 't': 7,
            'u': 8, 'v': 8, 'w': 8,
            'x': 9, 'y': 9, 'z': 9
        }
        
        # construct the prefixSum array
        n = len(word)
        prefix_sum = [0] * n
        prefix_sum[0] = ch_to_vals[word[0]]
        for i in range(1, n):
            prefix_sum[i] = prefix_sum[i-1] + ch_to_vals[word[i]]
        
        # iterate each substring possibility
        count = 0
        for i in range(0, n):
            for j in range(i, n):
                curr_sum = prefix_sum[j]-prefix_sum[i-1] if i-1>=0 else prefix_sum[j]
                curr_len = j-i+1
                if curr_sum % curr_len == 0: count += 1
        
        return count
        