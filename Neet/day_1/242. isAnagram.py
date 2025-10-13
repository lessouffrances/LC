class Solution: 
    def isAnagram(self, s: str, t: str) -> bool:
        s = sorted(s)
        t = sorted(t)

        if s == t:
            return True
        return False
    ##############################################
    # if len(s) != len(t):
    #         return False
        
    #     countS, countT = {}, {}

    #     for i in range(len(s)):
    #         countS[s[i]] = 1 + countS.get(s[i], 0)
    #         countT[t[i]] = 1 + countT.get(t[i], 0)

    #         # print(countS[s[i]], countT[t[i]])

    #     for char in countS:
    #         if countS[char] != countT.get(char, 0):
    #             return False
    #     return True
            
def main():
    ''' s = 'anagram'
    t = 'naragam'  '''

    s = 'car'
    t = 'rat'
    
    self = Solution()
    print(Solution.isAnagram(self, s, t))

main()
    
    
    
   


