class Solution 
{
    public:
    int getKth(int lo, int hi, int k) 
    {
        vector<pair<int, int>> container;
        for (int num=lo; num<=hi; num++) {
            container.push_back( {num, computePowerVal(num)} );
        }

        // sort the container by the .second
        sort(container.begin(), container.end(), [](const auto& a, const auto& b){
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        return container[k-1].first;
    }
    private:
    unordeered_map<int, int> powerVals;
    int computePowerVal(int val) {
        if (val == 1) return 0;
        if powerVals.count(val) return powerVals[val];

        int steps = 0;
        if (val % 2 == 0) {
            steps += 1 + computePowerVal(val / 2);
        } else {
            steps += 1 + computePowerVal(3 * val + 1);
        }

        return steps;
    }
};