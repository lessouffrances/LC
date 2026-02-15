class SparseVector 
{
    public:
    SparseVector(vector<int> &nums) 
    {
        int size = nums.size();
        for (int i=0; i<size; i++) {
            vector[i] = nums[i];
        }
    }
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) 
    {
        if (vec.getSize() != size) return -1;
    
        unordered_map<int, int> otherVec = vec.getVector();
        int res = 0;
        for (auto& [idx, num] : vector) {
            if (otherVec.count(idx)) {
                res += num * otherVec[idx];
            }
        }
        return res;
    }
    private:
    int size;
    unordered_map<int, int> vector; // { idx, num }

    unordered_map<int, int> getVector()
    {
        return vector;
    }

    int getSize()
    {
        return size;
    }
};

    
