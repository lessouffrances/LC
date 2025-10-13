from collections import Counter
class Solution:
    def minAnagramLength(self, s: str) -> int:
        n = len(s)

        for length in range(1, n+1):
            if n%length != 0:
                continue

            target = s[:length]
            targetCounter = Counter(target)
            
            ok = True
            for i in range(0, n, length):
                chunk = s[i: i+length]
                if Counter(chunk) != targetCounter:
                    ok = False
                    break
            if ok: return length
        return -1

def main():
    self = Solution
    s = "abba"
    s = "cdef"
    Solution.minAnagramLength(self, s)
main()