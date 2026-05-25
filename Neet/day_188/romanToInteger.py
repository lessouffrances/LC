class Solution(object):
    def romanToInt(self, s):
        if not s:
            return 0

        roman_to_int = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        
        n = len(s)
        res = 0
        for i in range(n):
            if i+1 < n and roman_to_int[s[i]] < roman_to_int[s[i+1]]:
                res -= roman_to_int[s[i]]
            else:
                res += roman_to_int[s[i]]
            
        return res


        