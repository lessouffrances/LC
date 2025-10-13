class Solution:
    def minMeetingRooms(self, intervals):
        if not intervals:
            return 0
        
        intervals.sort(key=lambda x:x[1])
        lastIncludedInterval = intervals[0]
        intervals[0] = []

        for i in range(1, len(intervals)):
            if intervals[i][0] >= lastIncludedInterval[1]:
                lastIncludedInterval = intervals[i]
                intervals[i] = []
        print(intervals)

        nextIntervals = []
        for interval in intervals:
            if interval != []:
                nextIntervals.append(interval)
        print("nextIntervals is: ", nextIntervals)

        if not nextIntervals:
            return 1

        return 1 + self.minMeetingRooms(nextIntervals)

def main():
    solution = Solution()
    intervals = [[0,30],[5,10],[15,20]] #2
    # intervals = [[7,10],[2,4]] #1
    # intervals = [[2,11],[6,16],[11,16]] #2
    intervals = [[2,15],[36,45],[9,29],[16,23],[4,9]] #2
    print(solution.minMeetingRooms(intervals))
main()