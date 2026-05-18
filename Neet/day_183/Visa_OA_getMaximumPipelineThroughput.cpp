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