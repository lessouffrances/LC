class Solution 
{
    public:
    int getKth(int lo, int hi, int k) 
    {
        vector<pair<int, int>> numToPower;
        for (int num=lo; num<=hi; num++) {
            int power = computePowerValue(num);
            numToPower.push_back( {num, power} );
        }

        // sort the numToPower by .second
        sort(numToPower.begin(), numToPower.end(), [](
            const auto& a, const auto& b
        ){
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        return numToPower[k-1].first;

    }

    private:
    unordered_map<int, int> lookUp; // {int : powerValue}]
    int MOD = 1e9 + 7;
    int computePowerValue(int val)
    {
        if (val == 1) {
            return 0;
        }

        // check memo
        if (lookUp.count(val)) {
            return lookUp[val];
        }

        int steps = 0;
        if (val % 2 == 0) {
            steps += 1 + computePowerValue(val / 2);
        } else {
            steps += 1 + computePowerValue(val * 3 + 1);
        }
        lookUp[val] = steps;
        return steps;
    }
};