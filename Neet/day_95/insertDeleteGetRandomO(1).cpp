class RandomizedSet 
{
    public:
    RandomizedSet() {}
    
    bool insert(int val) 
    {
        if (valToIdx.count(val)) return false;
        int idx = nums.size();
        valToIdx[val] = idx;
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) 
    {
        if (!valToIdx.count(val)) return false;
        // get the idx 
        int idx = valToIdx[val];

        // place the back to the idx 
        nums[idx] = nums.back();
        valToIdx[nums.back()] = idx;

        // delete back
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
    
