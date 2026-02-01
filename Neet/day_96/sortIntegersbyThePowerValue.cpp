class Solution 
{
    public:
    int getKth(int lo, int hi, int k) 
    {
        if (lo > hi) return -1;

        vector<pair<int, int>> numToPowerVal;

        for (int i=lo; i<=hi; i++) {
            numToPowerVal.push_back( {i, computePowerVal(i)} );
        }

        // sort the numToPowerVal by powerVal
        sort(numToPowerVal.begin(), numToPowerVal.end(), [](const auto& a, const auto& b){
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        return numToPowerVal[k-1].first;
    }
    private:
    int computePowerVal(int val) 
    {
        if (val == 1) return 0;

        int steps = 0;
        if (val % 2 == 0) {
            steps += 1+computePowerVal(val / 2);
        } else {
            steps += 1+computePowerVal(3 * val + 1);
        }

        return steps;
    }
};