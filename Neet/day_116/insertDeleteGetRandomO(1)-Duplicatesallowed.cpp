class RandomizedCollection 
{
    public:
    RandomizedCollection() {}

    bool insert(int val) 
    {
        if (!valToIdxes.count(val)) {
            // not present
            vals.push_back(val);
            int idx = vals.size()-1;
            valToIdxes[val].push_back(idx);
            return true;
        } 
        // present
        vals.push_back(val);
        int idx = vals.size()-1;
        valToIdxes[val].push_back(idx);
        return false;
    }
    bool remove(int val) 
    {
        if (!valToIdxes.count(val)) return false;

        // take one occurrence of the val
        int idx = valToIdxes[val].back();
        valToIdxes[val].pop_back();

        // if the deletion leads to zero
        if (valToIdxes[val].empty()) {
            valToIdxes.erase(val);
        }

        // swap the vals[idx] with vals.back();
        int backVal = vals.back();
        int backIdx = vals.size()-1;
        // only when the removed integer is not the one at the back, do:
        if (idx != backIdx) {
            vals[idx] = backVal;
            // update idx for backVal
            // extract the idxes vector
            auto& idxes = valToIdxes[backVal];
            // find and replace
            *find(idxes.begin(), idxes.end(), backIdx) = idx;
        }

        // remove the current back
        vals.pop_back();
        return true;
    }
    int getRandom() 
    {
        int size = vals.size();
        int idx = rand() % size;
        return vals[idx];
    }
    private:
    vector<int> vals;
    unordered_map<int, vector<int>> valToIdxes;
};
    
    