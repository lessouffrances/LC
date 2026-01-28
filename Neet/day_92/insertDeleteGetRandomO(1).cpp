class RandomizedSet 
{
    public:
    RandomizedSet() {}
   
    bool insert(int val) 
    {
        if (!valToIdx.count(val)) {
            valToIdx[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val) 
    {
        if (!valToIdx.count(val)) {
            return false;
        }
        int idx = valToIdx[val];
        int lastVal = nums.back();

        // move the lastVal to idx
        nums[idx] = lastVal;
        valToIdx[lastVal] = idx;

        // delete the last idx
        nums.pop_back();
        valToIdx.erase(val);

        return true;
    }

    int getRandom() 
    {
        int idx = rand() % nums.size();
        return nums[idx];
    }

    private:
    vector<int> nums; 
    unordered_map<int, int> valToIdx;
};