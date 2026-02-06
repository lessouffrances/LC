class SparseVector 
{
    public:
    SparseVector(vector<int> &nums) 
    {
        size = nums.size();
        for (int i=0; i<size; i++) {
            if (nums[i] != 0) {
                idxToNum[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) 
    {
        if (size != vec.getSize()) return -1;

        unordered_map<int, int> idxToNum2 = vec.getIdxToNum();
        int res = 0;
        int n = idxToNum.size();
        for (auto& [key, val] : idxToNum) {
            if (idxToNum2.count(key)) {
                res += val * idxToNum2[key];
            }

        }
        return res;
    }

    unordered_map<int, int> getIdxToNum() 
    {
        return idxToNum;
    }

    int getSize() 
    {
        return size;
    }

    private:
    int size;
    unordered_map<int, int> idxToNum;
};
    