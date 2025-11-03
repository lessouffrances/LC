class Solution:
    def canAttendMeetings(self, intervals) -> bool:
        if len(intervals) == 0 or not intervals:
            return True
        intervals.sort(key=lambda x:x[1])
        
        res = 1
        lastIncludedInterval = intervals[0]

        for i in range(1, len(intervals)):
            if intervals[i][0] >= lastIncludedInterval[1]:
                res += 1
                lastIncludedInterval = intervals[i]

        return res == len(intervals) 
        
        