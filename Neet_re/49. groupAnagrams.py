from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs):
        res = defaultdict(list)
        print(res)

        for str in strs:
            count = [0] * 26
            for char in str:
                count[ord(char)-ord("a")] += 1
            res[tuple(count)].append(str)

        print(res.values())
        return res.values()
        
def main():
    self = Solution
    strs = ["eat","tea","tan","ate","nat","bat"]
    Solution.groupAnagrams(self, strs)
main()