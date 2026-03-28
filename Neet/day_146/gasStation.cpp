


// Time: O(N)
// Space: O(1)

class Solution 
{
    public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        if (gas.empty() || cost.empty()) return -1;
        int n = gas.size();

        int globalTotal = 0, start = 0, currTank = 0;
        for (int i=0; i<n; i++) {
            int net = gas[i]-cost[i];
            currTank += net;
            globalTotal += net;

            if (currTank < 0) {
                start = i+1;
                currTank = 0; // reset
            }
        }
        return globalTotal >= 0 ? start : -1;
    }
};