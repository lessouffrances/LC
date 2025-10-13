from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs):
        dictionary = defaultdict(list)
        res = []

        for str in strs:
            strMetric = [0] * 26
            for char in str:
                strMetric[ord(char)-ord('a')] += 1
            strMetric = tuple(strMetric)
            dictionary[strMetric].append(str)
        print(dictionary)

        for value in dictionary.values():
            print(value)
            res.append(value)
        print(res)

def main():
    self = Solution
    # strs = ["eat","tea","tan","ate","nat","bat"]
    # strs = [""]
    strs = ["a"]
    Solution.groupAnagrams(self, strs)
main()