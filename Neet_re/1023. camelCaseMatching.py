class Solution:
    def camelMatch(self, queries, pattern: str):
        lst = []
        res = []
        patternLst = Solution.decompose(self, pattern)

        for query in queries:
            lst = Solution.decompose(self, query)
            if len(lst) != len(patternLst):
                res.append(False)
                continue
            ok = True
            for i, group in enumerate(lst):
                if Solution.isSubsequence(self, patternLst[i], group):
                    continue
                else:
                    ok = False
                    res.append(False)
                    break
            if ok: res.append(True)
        print(res)
        return res

    def decompose(self, string):
        currGroup = ""
        res = []
        l, r = 0, 0
        for r in range(len(string)):
            if currGroup and string[r].isupper(): 
                res.append(currGroup)
                l = r
                currGroup = string[l]
                continue
            else:
                currGroup += string[r]
        res.append(currGroup)
        if res[0][0].islower():
            res.remove(res[0])
        print(res)
        return res
    
    def isSubsequence(self, string, target):
        i = 0
        for char in target:
            if i < len(string) and string[i] == char:
                i += 1
        return i == len(string)
    
def main():
    self = Solution
    # queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]
    # [true, false, true, true, false]
    # queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]
    # [true, false, true, false, false]
    
    pattern = "FB"
    pattern = "FoBa"
    # Solution.camelMatch(self, queries, pattern)
    Solution.decompose(self, "aaaFB")
    # print(Solution.isSubsequence(self, "Fo", "Fooa"))
main()