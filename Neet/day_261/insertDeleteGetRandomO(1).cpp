class RandomizedSet 
{
    private:
    unordered_map<int, int> valToIdx;
    vector<int> vals;

    public:
    RandomizedSet() {}
    
    bool insert(int val) 
    {
        if (valToIdx.count(val)) return false;
        vals.push_back(val);
        int size = vals.size();
        valToIdx[val] = size-1;
        return true;
    }
    
    bool remove(int val) 
    {
        if (!valToIdx.count(val)) return false;
        int idx = valToIdx[val];
        int lastIdx = vals.size()-1;
        int lastIdxVal = vals.back();
        swap(vals[idx], vals[lastIdx]);
        vals.pop_back();
        valToIdx[lastIdxVal] = idx;
        valToIdx.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        // make sure the idx is between [0, vals.size()-1]
        int randomIdx = rand() % vals.size();
        return vals[randomIdx];
    }
};
    
    