class Solution:
    def canAttendMeetings(self, intervals) -> bool:
        if not intervals or len(intervals) == 0:
            return True
        intervals.sort(key=lambda x:x[1])
        print(intervals)
        lastIncludedInterval = intervals[0]
        nonOverlapping = [ intervals[0] ]

        for i in range(1, len(intervals)):
            if intervals[i][0] >= lastIncludedInterval[1]:
                nonOverlapping.append(intervals[i])
                lastIncludedInterval = intervals[i]
            print(nonOverlapping)
        
        return len(nonOverlapping) == len(intervals)



def main():
    solution = Solution()
    intervals = [[0,30],[5,10],[15,20]] #false
    intervals = [[7,10],[2,4]] #true
    intervals = [[0,30],[60,240],[90,120]] #false
    print(solution.canAttendMeetings(intervals))
main()


