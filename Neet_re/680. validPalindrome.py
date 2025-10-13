class Solution:
    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s)-1
        while l<r:
            if s[l] != s[r]:
                skipL, skipR = s[l+1: r+1], s[l: r]
                return (skipL == skipL[::-1] or skipR == skipR[::-1])
            l, r = l+1, r-1
        return True

        #################### inefficient #################
        # charList = list(s)
        # print(charList)

        # for i in range(len(charList)):
        #     print(charList[: i])
        #     print(charList[i+1 :][::-1])

        #     if charList[:i ] == charList[i+1 :][::-1]:
        #         return True
        # return False



def main():
    self = Solution
    s = "abca" # true

    print(Solution.validPalindrome(self, s))
main()