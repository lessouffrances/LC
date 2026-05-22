class Solution(object):
    def maxScoreSightseeingPair(self, values):
        if not values:
            return 0
        
        res = -float('inf')
        n = len(values)
        max_left = values[0]+0

        for j in range(1, n):
            res = max(values[j]-j+max_left, res)
            max_left = max(max_left, values[j]+j)
        return res
        