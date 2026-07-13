class Vector2D 
{
    public:
    Vector2D(vector<vector<int>>& vec) 
    {
        // flatten
        for (auto& v : vec) {
            for (int num : v) {
                flatVec.emplace_back(num);
            }
        }
        // reset 
        pt = 0;
    }
    
    int next() 
    {
        return flatVec[pt++];
    }
    
    bool hasNext() 
    {
        return pt < flatVec.size();
    }

    private:
    // last valid idx is 1DVector.size()-1
    vector<int> flatVec;
    int pt;
};
    
    