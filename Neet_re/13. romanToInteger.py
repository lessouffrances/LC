class Solution:
    def romanToInt(self, s: str) -> int:
        charToNum = {'I': 1, 
                     'V': 5, 
                     'X': 10, 
                     'L': 50, 
                     'C': 100,
                     'D': 500,
                     'M': 1000
                     }
        res = 0
        i = 0
        while i < len(s):
            if i+1 < len(s) and charToNum[s[i]] < charToNum[s[i+1]]:
                res += charToNum[s[i+1]] - charToNum[s[i]]
                i += 2
            else:
                res += charToNum[s[i]]
                i += 1
        return res



            
            

        


def main():
    self = Solution
    s = "III"
    # s = "LVIII"
    # s = "MCMXCIV"
    print(Solution.romanToInt(self, s))
main()