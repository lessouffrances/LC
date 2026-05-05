import heapq

class Solution(object):
    def findKthLargest(self, nums, k):
        if not nums:
            return -1

        min_heap = []
        for num in nums:
            heapq.heappush(min_heap, num)
        
        time_to_pop = len(nums)-k
        while time_to_pop > 0:
            time_to_pop -= 1
            heapq.heappop(min_heap)
        
        return min_heap[0]

        