from collections import defaultdict
class Solution(object):
    def groupAnagrams(self, strs):
        if not strs:
            return []

        record = defaultdict(list)

        for word in strs:
            metric = [0] * 26
            for ch in word:
                metric[ord(ch)-ord('a')] += 1
            
            record[tuple(metric)].append(word)
        
        res = []
        for metric, group in record.items():
            res.append(group)
        return res

            
        
