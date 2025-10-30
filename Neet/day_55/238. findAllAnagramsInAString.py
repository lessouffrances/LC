import collections

class Solution:
    def findAnagrams(self, s: str, p: str):
        # iterate the char in s, for each length-len(s) code chunk, check if the metrics are equal
        res = []
        target = collections.Counter(p)
        for i in range(len(s)-len(p)+1):
            curr_chunk = s[i: i+len(p)]
            if collections.Counter(curr_chunk) == target:
                res.append(i)
        
        return res
                

def main():
    solution = Solution()
    s = "cbaebabacd"
    p = "abc" #[0, 6]

    # s = "abab"
    # p = "ab" #[0, 1, 2]
    solution.findAnagrams(s, p)
main()