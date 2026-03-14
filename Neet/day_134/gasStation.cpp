


// Time: O(N)
// Space: O(1)

class Solution 
{
    public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        if (gas.empty() || cost.empty()) return -1;

        int n = gas.size();
        int tank = 0, total = 0, start = 0;
        for (int i=0; i<n; i++) {
            int net = gas[i] - cost[i];
            tank += net;
            total += net;

            if (tank < 0) {
                start = i+1;
                tank = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};