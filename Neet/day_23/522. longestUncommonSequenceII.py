class Solution:
    def findLUSlength(self, strs) -> int:
        strs.sort(key=len, reverse=True)
        print(strs)

        for i, word in enumerate(strs):
            found = True
            for j in range(len(strs)):
                if i != j:
                    if Solution.isSubsequence(self, word, strs[j]):
                        found = False
                        break
            if found:
                return len(word)
        return -1    

    def isSubsequence(self, s, t):
        if len(s) > len(t):
            return False
        
        i = 0
        for char in t:
            if i < len(s) and s[i] == char:
                i += 1
        return i == len(s)
        
    
def main():
    solution = Solution()
    strs = ["aba","cdc","eae"]
    # strs = ["aaa","aaa","aa"]
    # strs = ["aaa", "acb"]
    print(solution.findLUSlength(strs))
main()