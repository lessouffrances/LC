class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        
        # n = 0
        # for i in range(len(s) - 1, int(len(s) / 2) - 1, -1):
        #     var = s[i]
        #     s[i] = s[n]
        #     s[n] = var
        #     n += 1
        #     if n < len(s):
        #         continue

        l, r = 0, len(s) - 1
        while l < r:
            s[l], s[r] = s[r], s[l]
            l += 1
            r -=1


        print(s)
            


def main():
    self = Solution()
    s = ["h","e","l","l","o"]
    Solution.reverseString(self, s)


main()