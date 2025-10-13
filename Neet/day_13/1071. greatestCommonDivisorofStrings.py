import math
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        length = math.gcd(len(str1), len(str2))
        return str1[: length]
          

def main():
    self = Solution
    str1 = "ABCABC"
    str2 = "ABC"
    # # output = "ABC"
    # str1 = "ABABAB"
    # str2 = "ABAB"
    # # output = "ABAB"
    # str1 = "LEET"
    # str2 = "CODE"
    # # output = ""


    print(Solution.gcdOfStrings(self, str1, str2))


main()