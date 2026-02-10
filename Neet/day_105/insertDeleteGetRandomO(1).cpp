class RandomizedSet 
{
    public:
    RandomizedSet() {}
    
    bool insert(int val) 
    { 
        if (!valToIdx.count(val)) {
            vals.push_back(val);
            valToIdx[val] = vals.size()-1;
            return true;
        }      
        return false;
    }
    
    bool remove(int val) 
    {
        if (valToIdx.count(val)) {
            int idx = valToIdx[val];
            int backIdx = vals.size()-1;

            // swap in vals
            vals[idx] = vals.back();
            valToIdx[vals.back()] = idx;

            valToIdx.erase(val);
            vals.pop_back();
            return true;
        }
        return false;
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
