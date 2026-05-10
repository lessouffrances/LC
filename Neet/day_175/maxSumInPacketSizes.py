class Solution:
    def maximizePacketSum(self, packet_sizes, k):
        if len(packet_sizes) == 0 or k > len(packet_sizes):
            return -1
        
        window_counter = {}
        left = 0
        curr_sum = 0
        max_sum = 0
        for right in range(len(packet_sizes)):
            window_counter[packet_sizes[right]] = window_counter.get(packet_sizes[right], 0)+1
            curr_sum += packet_sizes[right]
            while window_counter[packet_sizes[right]] > 1 or right-left+1 > k:
                window_counter[packet_sizes[left]] -= 1
                curr_sum -= packet_sizes[left]
                left += 1
            if right - left + 1 == k:
                max_sum = max(max_sum, curr_sum)
        return max_sum