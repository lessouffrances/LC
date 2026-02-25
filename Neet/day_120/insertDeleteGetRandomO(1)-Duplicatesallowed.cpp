class RandomizedCollection 
{
    public:
    RandomizedCollection() {}

    bool insert(int val) 
    {
        if (!valToIdxes.count(val)) {
            vals.push_back(val);
            int idx = vals.size()-1;
            valToIdxes[val].push_back(idx);
            return true;
        }
        vals.push_back(val);
        int idx = vals.size()-1;
        valToIdxes[val].push_back(idx);
        return false;
    }
    bool remove(int val) 
    {
        if (!valToIdxes.count(val)) return false;

        // have an index of the val
        int valIdx = valToIdxes[val].back();
        valToIdxes[val].pop_back();

        if (valToIdxes[val].empty()) valToIdxes.erase(val);

        int backNum = vals.back();
        int backIdx = vals.size()-1;

        if (valIdx != backIdx) {
            vals[valIdx] = backNum;
            auto& idxes = valToIdxes[backNum];
            auto iter = find(idxes.begin(), idxes.end(), backIdx);
            *iter = valIdx;
        }

        vals.pop_back();
        return true;
    }
    int getRandom() 
    {
        if (vals.empty()) return -1;
        int random = rand() % vals.size();
        return vals[random];
    }

    private:
    vector<int> vals; 
    unordered_map<int, vector<int>> valToIdxes; // val to vector of pos
};