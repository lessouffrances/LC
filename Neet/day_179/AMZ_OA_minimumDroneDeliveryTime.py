class Solution:
    def getMinTravelTime(self, m, transitionTime, requestedHubs):
        if not transitionTime or not requestedHubs:
            return 0;
        
        # make the requestedHubs a 0-based array
        hubs = []
        for hub in requestedHubs:
            hubs.append(hub-1)
        
        # build the prefixSum

        prefix_sum = [0] * m
        for i in range(1, m):
            prefix_sum[i] = prefix_sum[i-1] + transitionTime[i-1]
        full_ring = prefix_sum[m-1] + transitionTime[m-1]

        total_time = 0
        curr_pos = 0
        for hub in hubs:
            total_time += self.minCost(curr_pos, hub, prefix_sum, full_ring)
            curr_pos = hub

        return total_time

    def minCost(self, src, dest, prefixSum, fullRing):
        clockwise = abs(prefixSum[dest]-prefixSum[src])
        return min(clockwise, fullRing-clockwise)