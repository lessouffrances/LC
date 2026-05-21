// Question 3 — Maximum Pipeline Throughput
// A data pipeline consists of n services connected in series, 
// where the output of service i is the input to service i+1. 
// The throughput of the i-th service is throughput[i] messages per minute. 

// Each service can be scaled up independently. 
// Scaling up the i-th service one unit costs scalingCost[i], 
// and after scaling up x times, the service processes throughput[i] * (1+x) messages per minute. 
// Given a budget, find the maximum possible throughput of the pipeline.

// Function Description:
// long getMaxThroughput(int[] throughput, int[] scalingCost, int budget)
// Returns: long — the maximum possible throughput given the budget.

// Example:
// throughput=[4,2,7], scalingCost=[3,5,6], budget=32
// Output: 10

// Constraints:
// 1 <= n <= 10^5
// 1 <= throughput[i] <= 10^9
// 1 <= scalingCost[i] <= 10^9
// 1 <= budget <= 10^9

class Solution
{
    public:
    int getMaxThroughput(vector<int> throughput, vector<int> scalingCost, int budget)
    {
        if (throughput.empty()) return 0;

        // set the lo && hi bounds for the targetThoughput
        // and conduct binary search on it
        long lo = *min_element(throughput.begin(), throughput.end());
        long hi = (long)*max_element(throughput.begin(), throughput.end()) * (budget / minScalingCost + 1);

        int res = lo;
        while (lo<=hi) {
            int mid = lo + (hi-lo) / 2;
            if (canAchieve(mid, throughput, scalingCost, budget)) {
                res = mid;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return res;
    }
    private:
    // look for each possibilities to see 
    // if the targetThourghput can be satisfied using the existing budge
    bool canAchieve(long targetThroughput, vector<int> throughput, vector<int> scalingCost, int budget)
    {
        long totalCost = 0;
        int n = throughput.size();
        for (int i=0; i<n; i++) {
            // this service is good
            if (throughput[i] >= targetThroughput) continue;

            // equation: throughput[i] * (1+x) >= targetThroughput
            // solve for x:
            // (1+x) = targetThrouput / throughput[i]
            long x = (targetThroughput + throughput[i] - 1) / throughput[i] - 1;
            totalCost += x * scalingCost[i];
            if (totalCost > budget) return false;
        }
        return true;
    }

};

