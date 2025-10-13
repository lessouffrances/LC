class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        l, r = 0, len(s) - 1
        while l < r:
            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1

        print(s)

def main():
    self = Solution()
    s = ["H","a","n","n","a","h"]
    # s.reverse()
    # print(s)
    Solution.reverseString(self, s)
main()