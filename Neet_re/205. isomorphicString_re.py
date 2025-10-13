class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        hashSToT, hashTToS = {}, {}

        for ss, tt in zip(s, t):
            hashSToT[ss] = tt
            hashTToS[tt] = ss
        
        print(hashSToT)
        print(hashTToS)

        for i in range(len(s)):
            if hashSToT[s[i]] == t[i] and hashTToS[t[i]] == s[i]:
                continue
            else:
                return False
        return True 

def main():
    self = Solution()
    s = "foo"
    t = "bar"
    print(Solution.isIsomorphic(self, s, t))
main()