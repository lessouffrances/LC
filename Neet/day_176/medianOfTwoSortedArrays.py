import heapq

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        nums1.extend(nums2)
        min_heap = []
        max_heap = [] # negative values

        for num in nums1:
            heapq.heappush(max_heap, -num)
            heapq.heappush(min_heap, -max_heap[0])
            heapq.heappop(max_heap)

            if len(min_heap) > len(max_heap):
                heapq.heappush(max_heap, -min_heap[0])
                heapq.heappop(min_heap)

        if len(max_heap) > len(min_heap):
            return float(-max_heap[0])
        return float(-max_heap[0] + min_heap[0]) / 2


        