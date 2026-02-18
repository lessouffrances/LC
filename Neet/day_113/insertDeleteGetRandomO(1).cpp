class RandomizedSet 
{
    public:
    RandomizedSet() {}
    bool insert(int val) 
    {
        if (valToIdx.count(val)) return false;
        vals.push_back(val);
        int n = vals.size();
        valToIdx[val] = n-1;
        return true;
    }
    
    bool remove(int val) 
    {
        if (!valToIdx.count(val)) return false;
        // vals
        int idx = valToIdx[val];
        vals[idx] = vals.back();
        valToIdx[vals.back()] = idx;

        // remove 
        vals.pop_back();
        valToIdx.erase(val);
        return true;
    }
    int getRandom() 
    {
        int randomIdx = rand() % vals.size();
        return vals[randomIdx];
    }
    private:
    vector<int> vals;
    unordered_map<int, int> valToIdx;
};
    