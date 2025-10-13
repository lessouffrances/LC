class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {"a", "e", "i", "o", "u"}
        l = 0
        r = l+k

        maxCount = 0
        while r <= len(s):
            currCount = 0
            for char in s[l: r]:
                if char in vowels:
                    currCount += 1
                else:
                    continue
            maxCount = max(maxCount, currCount)
            l += 1
            r = l+k

        print(maxCount)
        return maxCount

def main():
    self = Solution
    s = "abciiidef"
    k = 3
    # s = "aeiou"
    # k = 2
    # s = "leetcode"
    # k = 3
    print(Solution.maxVowels(self, s, k))
main()