from collections import Counter
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res = set()
        left = set()
        right = Counter(s)

        for i in range(len(s)):
            right[s[i]] -= 1
            if right[s[i]] == 0:
                right.pop(s[i])
            
            for j in range(26):
                char = chr(ord("a")+j)
                if char in right and char in left:
                    res.add((s[i], char))
            left.add(s[i])

        return len(res)
    
def main():
    self = Solution
    s = "aabca"
    s = "adc"
    s = "bbcbaba"
    Solution.countPalindromicSubsequence(self, s)
main()