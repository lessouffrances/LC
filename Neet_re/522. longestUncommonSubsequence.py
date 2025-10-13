class Solution:
    def findLUSlength(self, strs) -> int:
        strs = sorted(strs,key=len)
        print(strs)
        res = 0
        for i, word1 in enumerate(strs):

            ok = True
            count = 0
            for j, word2 in enumerate(strs):
                if i != j:
                    if Solution.isSubsequence(self, word1, word2):
                        ok = False
                        break
            if ok: count = len(word1)
            res = max(res, count)
        print(res)
        return res if res != 0 else -1

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
    # strs = ["aba","cdc","eae"]
    strs = ["aaa","aaa","aa"]
    strs = ["aaa","acb"] # 3
    Solution.findLUSlength(self, strs)
main()