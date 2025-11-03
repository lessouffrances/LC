class Solution:
    def eraseOverlapIntervals(self, intervals) -> int:
        if not intervals:
            return 0
        intervals = intervals.sort(key=lambda x:x[1])

        res = 1
        lastIncludedInterval = intervals[0]

        for i in range(1, len(intervals)):
            if intervals[i][0] >= lastIncludedInterval[1]:
                lastIncludedInterval = intervals[i]
                res += 1
        
        return (len(intervals)-res)
        
        