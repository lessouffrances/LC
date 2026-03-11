//                   i
// gas =   [1,2,3,4,5]
// cost = [3,4,5,1,2]
// tank = 6
// total = 0
// start = 
class Solution 
{
    public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int total = 0, tank = 0, start = 0;
        int n = gas.size();
        
        for (int i=0; i<n; i++) {
            // net gas gain/loss at station i
            int diff = gas[i] - cost[i];
            tank += diff;   // track local feasibility from current start
            total += diff;  // track global feasibility across all stations

            // if tank drops below 0, the current start can't reach station i
            // furthermore, no station between start and i can be a valid start either:
            // if any of them were valid, we would have had a non-negative tank up to i
            // so the next candidate is i+1
            if (tank < 0) {
                start = (i + 1) % n;
                tank = 0;   // reset tank for the new candidate start
            }
        }
        return total >= 0 ? start : -1;
    }
};

