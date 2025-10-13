class Solution:
    def eraseOverlapIntervals(self, intervals) -> int:
        if not intervals:
            return 0
        
        intervals.sort(key=lambda x:x[1])
        res = 1
        lastIncludedInterval = intervals[0]

        for i in range(1, len(intervals)):
            if intervals[i][0] >= lastIncludedInterval[1]:
                res += 1
                lastIncludedInterval = intervals[i]
        
        return (len(intervals)-res)
    
def main():
    solution = Solution()
    intervals = [[1,2],[2,3],[3,4],[1,3]] #1
    solution.eraseOverlapIntervals(intervals)
main()