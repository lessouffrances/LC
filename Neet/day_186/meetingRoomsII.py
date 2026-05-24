import heapq

class Solution(object):
    def minMeetingRooms(self, intervals):
        if not intervals:
            return 0
        
        intervals.sort()
        pq = []

        for interval in intervals:
            if pq and pq[0] <= interval[0]:
                heapq.heappop(pq)
            heapq.heappush(pq, interval[1])
        return len(pq)
