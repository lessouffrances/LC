from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str):
        
        ########### Second lease efficient ##############
        pCounter = Counter(p)

        k = len(p)
        currWindow = []
        res = []
        for r in range(len(s)):
            currWindow.append(s[r])
            if r>=k:
                currWindow.remove(s[r-k])
            print(currWindow)

            currWindowCounter = Counter(currWindow)
            if currWindowCounter == pCounter:
                res.append(r-k+1)
            
            print(res)
        print(res)
        return res

            
        ############# Least efficient #####################
        # pMetric = [0] * 26
        # for char in p:
        #     pMetric[ord(char)-ord("a")] += 1

        # k = len(p)
        # currWindow = []
        # res = []
        # for r in range(len(s)):
        #     currWindow.append(s[r])

        #     if r>=k:
        #         currWindow.remove(s[r-k])

        #     currWindowMetric = [0] * 26
        #     for char in currWindow:
        #         currWindowMetric[ord(char)-ord("a")] += 1
        #     if currWindowMetric == pMetric:
        #         res.append(r-k+1)

        # return res
    
def main():
    self = Solution
    s = "cbaebabacd"
    p = "abc"

    # s = "abab"
    # p = "ab"
    Solution.findAnagrams(self, s, p)

main()