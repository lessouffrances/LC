class Solution:
    def findLUSlength(self, strs) -> int:
        strs.sort(key=len, reverse=True)
        # print(strs)
    
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

    def isSubsequence(self, string, target):
        if len(string)>len(target):
            return False
        
        i = 0
        for char in target:
            if i<len(string) and string[i] == char:
                i += 1

        return i == len(string)





def main():
    self = Solution
    strs = ["aaa","aaa","aa"]
    strs = ["aba","cdc","eae"]
    print(Solution.findLUSlength(self, strs))
main()