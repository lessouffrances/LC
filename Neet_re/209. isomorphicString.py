class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        sList = list(s)
        tList = list(t)
        print(sList)
        print(tList)

        sTot, tTos = {}, {}

        for s, t in zip(sList, tList):
            if s in sTot and sTot[s] != t:
                return False
            elif t in tTos and tTos[t] != s:
                return False
            
            sTot[s] = t
            tTos[t] = s

        return True

        
        



def main():
    self = Solution
    s = "egg"
    t = "add"
    s = "eggg"
    t = "abcb"
    print(Solution.isIsomorphic(self, s, t))
    

main()