class RandomizedSet 
{
    public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (valToIdx.count(val)) return false;
        vals.push_back(val);
        int idx = vals.size()-1;
        valToIdx[val] = idx;
        return true;
    }
    
    bool remove(int val) {
        if (!valToIdx.count(val)) return false;
        int idx = valToIdx[val];
        // swap the vals[idx] with the last one
        int size = vals.size();
        int lastVal = vals[size-1];
        swap(vals[idx], vals[size-1]);
        valToIdx[lastVal] = idx;
        valToIdx.erase(val);
        vals.pop_back();
        return true;
    }
    
    int getRandom() {
        int randomIdx = rand() % vals.size();
        return vals[randomIdx];
    }

    private:
    vector<int> vals;
    unordered_map<int, int> valToIdx;
};