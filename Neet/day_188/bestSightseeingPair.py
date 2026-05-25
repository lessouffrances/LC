class Solution(object):
    def maxScoreSightseeingPair(self, values):

        # values[i] + i + values[j] - j
        score = -float('inf')
        max_left = values[0]+0
        for i in range(1, len(values)-1):
            score = max(max_left+values[i]-i, score);
            max_left = max(max_left, values[i]+i)
        
        return score
        