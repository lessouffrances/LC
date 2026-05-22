import heapq

class Solution(object):
    def longestDiverseString(self, a, b, c):
        max_heap = []
        if a > 0: heapq.heappush(max_heap, (-a, 'a'))
        if b > 0: heapq.heappush(max_heap, (-b, 'b'))
        if c > 0: heapq.heappush(max_heap, (-c, 'c'))

        res = ""

        while max_heap:
            count1, ch1 = heapq.heappop(max_heap)
            count1 = -count1

            n = len(res)
            if n >= 2 and res[n-1] == ch1 and res[n-2] == ch1:
                if not max_heap:
                    break
                count2, ch2 = heapq.heappop(max_heap)
                count2 = -count2
                res += ch2
                if count2 > 1: heapq.heappush(max_heap, (-(count2-1), ch2))
                heapq.heappush(max_heap, (-count1, ch1))
            else:
                res += ch1
                if count1 > 1: heapq.heappush(max_heap, (-(count1-1), ch1))
        return res