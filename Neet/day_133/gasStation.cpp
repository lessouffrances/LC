
// Time: O(N)
// Space: O(N)


class Solution 
{
    public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        if (gas.empty() || cost.empty()) return -1;

        vector<int> doubleGas = gas;
        vector<int> doubleCost = cost;
        doubleGas.insert(doubleGas.end(), gas.begin(), gas.end());
        doubleCost.insert(doubleCost.end(), cost.begin(), cost.end());

        int sizeOfRoute = gas.size();

        for (int startIdx=0; startIdx<sizeOfRoute; startIdx++) {
            if (canComplete(startIdx, sizeOfRoute, doubleGas, doubleCost)) return startIdx;
        }
        return -1;
    }

    private:
    bool canComplete(int startIdx, int sizeOfRoute, 
        vector<int>& doubleGas, vector<int>& doubleCost)
    {
        long long currGas = 0;
        for (int i=0; i<sizeOfRoute; i++) {
            currGas += (doubleGas[startIdx] - doubleCost[startIdx]);
            if (currGas < 0) return false;
            startIdx++;
        }
        return true;
    }
};