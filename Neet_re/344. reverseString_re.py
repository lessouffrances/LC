class Solution:
    def reverseString(self, s) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        def reverse(l, r):
            if l < r:
                s[l], s[r] = s[r], s[l]
                reverse(l+1, r-1)
        
        reverse(0, len(s)-1)

def main():
    self = Solution
    s = ["h","e","l","l","o"]
    s = ["H","a","n","n","a","h"]
    Solution.reverseString(self, s)
main()