from collections import defaultdict
class Solution:
    def numSpecialEquivGroups(self, words) -> int:
        hashMap = defaultdict(list)
        for word in words:
            hashMap[Solution.check(self, word)].append(word)

        print(len(hashMap))
        return len(hashMap)

    

    def check(self, word):
        even = list(word[::2])
        odd = list(word[1::2])
        even.sort()
        odd.sort()
        res = ""
        for i, j in zip(even, odd):
            res += i + j
        if len(even)>len(odd):
            res += even[-1]
        return res




    
def main():
    self = Solution
    words = ["abcd","cdab","cbad","xyzz","zzxy","zzyx"] 
    # words = ["abc","acb","bac","bca","cab","cba"]
    Solution.numSpecialEquivGroups(self, words)
    # Solution.check(self, "cdab")
main()
