class Solution(object):
    def maxNumberOfBalloons(self, text):
        if not text:
            return 0;
        
        INSTANCE = "balloon"
        collector = {}
        for ch in INSTANCE:
            collector[ch] = 0

        for ch in text:
            if ch in collector:
                collector[ch] += 1
        
        min_count = float('inf')
        for ch, count in collector.items():
            if count == 0:
                return 0

            if ch == 'l' or ch == 'o':
                min_count = min(min_count, count//2)
            else:
                min_count = min(min_count, count)
        return min_count
            