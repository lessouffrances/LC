from collections import Counter
class Solution:
    def minAnagramLength(self, s: str) -> int:
       ################# inefficient approach #############
        for i in range(len(s)-1, -1, -1): # -> this is what makes it inefficient
            currString = s[i: ]
            currStringCounter = Counter(currString)
            if len(s)%len(currString) != 0:
                continue

            step = len(currString)
            ok = True
            for i in range(0, len(s), step):
                currChunk = s[i: i+step]
                currChunkCounter = Counter(currChunk)
                if currChunkCounter != currStringCounter:
                    ok = False
                    break
            if ok: 
                return step
        return -1

        ############### efficient approach #############
        # n = len(s)
        # for length in range(1, n+1):
        #     if n%length != 0:
        #         continue

        #     target = s[:length]
        #     print(target)
        #     targetMetrics = Counter(target)

        #     ok = True
        #     for i in range(0, n, length):
        #         chunk = s[i: i+length]
        #         if Counter(chunk) != targetMetrics:
        #             ok = False
        #             break
        #     if ok: return length
        #     return -1
            
def main():
    self = Solution
    # s = "abba"
    s = "cdef"
    Solution.minAnagramLength(self, s)
main()