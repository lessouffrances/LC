#include <numeric>
#include <vector>
class Solution {
    public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) 
    {
        int sumGas = accumulate(gas.begin(), gas.end(), 0);
        int sumCost = accumulate(cost.begin(), cost.end(), 0);
        
        if (sumCost > sumGas) {
            return -1;
        }
        
        // construct the real problem
        // the real problem for index i is : 
        // newGas = gas [ i : ] + gas [ : i+1 ]   and   newCost = cost [ i : ] + cost [ : i+1 ]
        for (int i=0; i<gas.size(); i++) {
            // initialize arrays for the real problem
            vector<int> realGas, realCost;
            for (int j=i; j<gas.size(); j++) {
                realGas.push_back( gas[j] );
                realCost.push_back( cost[j] ); 
            }       
            
            for (int j=0; j<=i; j++) {
                realGas.push_back( gas[j] );
                realCost.push_back( cost[j] ); 
            }
            
            int currentState = 0;
            bool qualified = true;
            for (int k=0; k<realGas.size(); k++) {
                currentState += realGas[k]-realCost[k];
                if (currentState < 0) {
                    qualified = false;
                    currentState = 0;
                    break;
                }
            }
            
            if (qualified) {
                return i;
            }
        }
        return -1;
    }
};
