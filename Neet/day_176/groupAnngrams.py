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
            groups[tuple(metric)].append(word)
        
        
        res = []
        for _, group in groups.items():
            res.append(group)
        return res 