import heapq

class Solution(object):
    def topKFrequent(self, nums, k):
        if not nums:
            return []
        
        # build freq map
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0)+1

        min_heap = []
        for num, count in freq.items():
            heapq.heappush(min_heap, (count, num))
            if len(min_heap) > k:
                heapq.heappop(min_heap)

        res = []
        while min_heap:
            count, num = heapq.heappop(min_heap)
            res.append(num)

        return res
