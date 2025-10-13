class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowelSet = {"a", "e", "i", "o", "u"}
        l = 0
        r = l+k
        maxCount = 0

        while r <= len(s):
            currCount = 0
            for char in s[l: r]:
                if char in vowelSet:
                    currCount += 1

            maxCount = max(maxCount, currCount)
            l += 1
            r = l+k
    
        return maxCount

def main():
    self = Solution
    # s = "abciiidef"
    # k = 3
    # s = "aeiou"
    # k = 2
    s = "ibpbhixfiouhdljnjfflpapptrxgcomvnb"
    print(len(s))
    k = 33

    print(Solution.maxVowels(self, s, k))
main()