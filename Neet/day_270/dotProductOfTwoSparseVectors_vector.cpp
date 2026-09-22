class SparseVector 
{
    public:
    SparseVector(vector<int> &nums) 
    {
        for (int i=0; i<nums.size(); i++) {
            v.push_back( {i, nums[i]} );
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) 
    {
        int i=0, j=0;
        int total = 0;
        while (i < v.size() && j < vec.v.size()) {
            if (v[i].first == vec.v[j].first) {
                total += v[i].second * vec.v[j].second;
                i++;
                j++;
            } else {

                return -1;
            }
        }
        return total;
    }

    private:
    vector<pair<int, int>> v;
};
    
   