


class Solution 
{
    public:
    int getKth(int lo, int hi, int k) 
    {
        vector<int> vals;
        for (int i=lo; i<=hi; i++) {
            vals.push_back(i);
        }

        vector<int> powers;
        for (int i=lo; i<=hi; i++) {
            powers.push_back(getPowerValue(i));
        }

        vector<pair<int, int>> powerToVal;
        for (int i=0; i<vals.size(); i++) {
            powerToVal.push_back({ powers[i], vals[i] });
        }
        sort(powerToVal.begin(), powerToVal.end());

        return powerToVal[k-1].second;
    }
    private:
    int getPowerValue(int val)
    {
        int steps = 0;
        while (val != 1) {
            if (val % 2 == 0) {
                val /= 2;
            } else {
                val = 3*val+1;
            }
            steps++;
        }
        return steps;
    }
};