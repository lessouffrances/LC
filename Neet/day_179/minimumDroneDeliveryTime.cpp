// Problem Statement: Minimum Drone Delivery Travel Time
// Context:
// Amazon is expanding its next-generation drone delivery network, consisting of m hubs arranged in a circular ring (Hub 1 is adjacent to Hub m). A drone can move to either adjacent hub, and the travel time between Hub i and its neighbors is given by transitionTime[i].
// Amazon receives a list of priority delivery requests, where packages must be picked up or delivered to specific hubs in a given sequence, represented by the array requestedHubs of size n. Starting from Hub 1, calculate the minimum total travel time to fulfill all delivery requests in order.
// Note: Use 1-based indexing.

// Example:
// m = 3
// n = 4
// transitionTime = [3, 2, 1]
// requestedHubs = [1, 3, 3, 2]

// The drone begins at Hub 1:
// First hub is Hub 1 itself → 0 seconds
// Hub 1 → Hub 3, two options:
// Clockwise: 1 → 2 → 3, takes transitionTime[1] + transitionTime[2] = 3 + 2 = 5 seconds
// Counterclockwise: 1 → 3 directly, takes transitionTime[1] = 3 seconds ← shorter
// Already at Hub 3 → 0 seconds
// Hub 3 → Hub 2, two options:
// Clockwise: 3 → 2, takes transitionTime[3] = 1 second ← shorter

// Function Description:
// int m: number of hubs in the circular ring
// int[] transitionTime: travel time between Hub i and its neighbors (1-indexed)
// int[] requestedHubs: sequence of hubs to visit (1-indexed)

// Returns: int — the minimum total travel time to fulfill all requests

class Solution
{
    public:
    long long getMinTravelTime(int m, const vector<int>& transitionTime, 
        const vector<int>& requestedHubs) {
            if (transitionTime.empty() || requestedHubs.empty()) return 0;

            vector<int> hubs(requestedHubs.size());
            for (int i = 0; i < (int)requestedHubs.size(); i++) {
                hubs[i] = requestedHubs[i] - 1;
            }

            // Build prefixSum clockwise
            vector<long long> prefixSum(m, 0);
            for (int i=1; i<m; i++) {
                prefixSum[i] = prefixSum[i-1] + transitionTime[i-1];
            }
            long long fullRing = prefixSum[m-1] + transitionTime[m-1];

            long long totalTime = 0;
            int curr = 0;
            for (int hub : hubs) {
                totalTime += minCost(curr, hub, prefixSum, fullRing);
                curr = hub;
            }
            return totalTime;
    }

    private:
    // return the minCost from either clockwise or anti-clockwise
    long long minCost(int src, int dest, const vector<long long>& prefixSum, long long fullRing) 
    {
        long long clockwise = abs(prefixSum[dest]-prefixSum[src]);
        return min(clockwise, fullRing-clockwise);
    }
};