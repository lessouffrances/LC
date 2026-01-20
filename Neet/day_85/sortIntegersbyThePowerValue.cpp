class Solution 
{
    public:
    int getKth(int lo, int hi, int k) 
    {
        vector<pair<int, int>> container; // { num : powerValue }
        for (int num=lo; num<=hi; num++) {
            container.push_back( { num, computePowerValue(num) } );
        }

        sort(container.begin(), container.end(), [](const auto& a, const auto& b){
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        return container[k-1].first;
    }

    private:
    unordered_map<int, int> lookUp; // { val : powerValue }
    int computePowerValue(int val)
    {
        if (val == 1) return 0;
        if (lookUp.count(val)) return lookUp[val];

        int steps = 0;
        if (val % 2 == 0) {
            steps += 1 + computePowerValue(val / 2);
        } else {
            steps += 1 + computePowerValue(3 * val + 1);
        }

        lookUp[val] = steps;
        return steps;
    }
};