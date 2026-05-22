# T: O(N * K), where N is the number of words and K is the avg length of each word
# S: O(N * K)
from collections import defaultdict
class Solution(object):
    def groupAnagrams(self, strs):
        if not strs:
            return []
        
        groups = defaultdict(list)
        for word in strs:
            metric = [0] * 26
            for ch in word:
                metric[ord(ch)-ord('a')] += 1
            if tuple(metric) not in groups:
                groups[tuple(metric)] = []
            groups[tuple(metric)].append(word)
        
        res = []
        for _, group in groups.items():
            res.append(group)
        return res