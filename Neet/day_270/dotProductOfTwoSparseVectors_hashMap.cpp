class SparseVector 
{
    public:
    SparseVector(vector<int> &nums) 
    {
        for (int i=0; i<nums.size(); i++) {
            idxToVal[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) 
    {
        if (getSize() != vec.getSize()) return -1;
        int res = 0;
        for (auto& [idx, val] : idxToVal) {
            if (!vec.idxToVal.count(idx)) return -1;
            res += val * vec.idxToVal[idx];
        }
        return res;
    }

    private:
    unordered_map<int, int> idxToVal;

    const int getSize() {
        return idxToVal.size();
    }
};
    
    