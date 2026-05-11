class Solution:
    def maximizePacketSum(self, packetSizes, k):
        if not packetSizes:
            return 0

        n = len(packetSizes)
        window_counter = {}
        left = 0
        max_sum = -float('inf')
        curr_sum = 0

        for right in range(n):
            curr_sum += packetSizes[right]
            window_counter[packetSizes[right]] = window_counter.get(packetSizes[right], 0) + 1
            while window_counter[packetSizes[right]] > 1 or right-left+1>k:
                curr_sum -= packetSizes[left]
                window_counter[packetSizes[left]] -= 1
                left += 1

            if right-left+1 == k:
                max_sum = max(max_sum, curr_sum)
        return max_sum


