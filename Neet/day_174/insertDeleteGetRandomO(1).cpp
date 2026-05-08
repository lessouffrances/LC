class RandomizedSet 
{
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
        // swap the val with the last val
        int idx = valToIdx[val];
        int lastIdx = vals.size()-1;
        int lastVal = vals[lastIdx];
        swap(vals[idx], vals[lastIdx]);
        vals.pop_back();
        vals[idx] = lastVal;
        valToIdx[lastVal] = idx;
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
    
   