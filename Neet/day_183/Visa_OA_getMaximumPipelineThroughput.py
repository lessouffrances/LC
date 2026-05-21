# Question 3 — Maximum Pipeline Throughput
# A data pipeline consists of n services connected in series, 
# where the output of service i is the input to service i+1. 
# The throughput of the i-th service is throughput[i] messages per minute. 

# Each service can be scaled up independently. 
# Scaling up the i-th service one unit costs scalingCost[i], 
# and after scaling up x times, the service processes throughput[i] * (1+x) messages per minute. 
# Given a budget, find the maximum possible throughput of the pipeline.

# Function Description:
# long getMaxThroughput(int[] throughput, int[] scalingCost, int budget)
# Returns: long — the maximum possible throughput given the budget.

# Example:
# throughput=[4,2,7], scalingCost=[3,5,6], budget=32
# Output: 10

# Constraints:
# 1 <= n <= 10^5
# 1 <= throughput[i] <= 10^9
# 1 <= scalingCost[i] <= 10^9
# 1 <= budget <= 10^9

class Solution(object):
    def getMaxThroughput(self, throughput, scaling_cost, budget):
        lo = min(throughput)
        min_cost = min(scaling_cost)
        hi = max(throughput) * (budget // min_cost + 1)
        res = lo

        while lo <= hi:
            mid = lo + (hi - lo) // 2;
            if self.canAchieve(mid, throughput, scaling_cost, budget):
                res = mid
                lo = mid+1
            else:
                hi = mid-1
        return res
                
    def canAchieve(self, targetThroughput, throughput, scaling_cost, budget):
        total_cost = 0
        n = len(throughput)

        for i in range(n):
            if throughput[i] >= targetThroughput:
                continue
            x = (targetThroughput + throughput[i] - 1) // throughput[i] - 1
            total_cost += x * scaling_cost[i]
            if total_cost > budget:
                return False
        return total_cost <= budget