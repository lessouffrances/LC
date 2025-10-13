class Solution:
    def romanToInt(self, s: str) -> int:
        # symbolToValue = {"I": 1,
        #                  "V": 5,
        #                  "X": 10,
        #                  "L": 50,
        #                  "C": 100,
        #                  "D": 500,
        #                  "M": 1000,
        #                  "N": 0}
        # sum = 0
        # s = "N" + s + "N"
        # print(s)
        # for i in range(1, len(s) - 1):
        #     if symbolToValue[s[i + 1]] > symbolToValue[s[i]]:
        #         sum += symbolToValue[s[i + 1]] - symbolToValue[s[i]]
        #     elif symbolToValue[s[i - 1]] < symbolToValue[s[i]]:
        #         if i == 1:
        #             sum += symbolToValue[s[i]]
        #         else:
        #             continue
        #     else:
        #         sum += symbolToValue[s[i]]
        # print(sum)
        # return sum

        ##############################################################
        symbolToValue = {"I": 1,
                         "V": 5,
                         "X": 10,
                         "L": 50,
                         "C": 100,
                         "D": 500,
                         "M": 1000}
        res = 0

        for i in range(len(s)):
            if i + 1 < len(s) and symbolToValue[s[i]] < symbolToValue[s[i+1]]:
                res -= symbolToValue[s[i]]
            else:
                res += symbolToValue[s[i]] 
        
        return res

def main():
    self = Solution()
    s = "LVIII"
    Solution.romanToInt(self, s)
main()