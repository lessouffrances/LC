import heapq

class Solution(object):
    def minMeetingRooms(self, intervals):
        if not intervals:
            return 0
        
        intervals.sort()
        n = len(intervals)
        pq = []
        heapq.heappush(pq, intervals[0][1])

        for i in range(1, n):
            earliest_end_time = pq[0]
            if earliest_end_time <= intervals[i][0]:
                heapq.heappop(pq)
            heapq.heappush(pq, intervals[i][1])
            
        return len(pq)