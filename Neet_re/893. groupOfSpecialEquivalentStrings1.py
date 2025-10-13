from collections import Counter
from collections import defaultdict

class Solution:
    def numSpecialEquivGroups(self, words) -> int:
        counter = defaultdict(list)

        for word in words:
            wordMetric = Solution.getOddEvenMetrics(self, word)
            counter[wordMetric].append(word)
        print(len(counter))
        return len(counter)

    def getOddEvenMetrics(self, string):
        odd = []
        even = []
        for i, char in enumerate(string):
            if i%2 == 1: # odd
                odd.append(char)
            else:
                even.append(char)
        
        res = (sorted(odd), sorted(even))
        res = (tuple(sorted(odd)), tuple(sorted(even)))
        print(res)
        return res

def main():
    self = Solution
    words = ["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
    # words = ["abc","acb","bac","bca","cab","cba"]

    Solution.numSpecialEquivGroups(self, words)
    # Solution.getOddEvenMetrics(self, "abcd")
main()