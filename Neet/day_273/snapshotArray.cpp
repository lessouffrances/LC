class SnapshotArray 
{
    public:
    SnapshotArray(int length) 
    {
        this->length = length;
        history.resize(length);
        for (int i=0; i<length; i++) {
            history[i].push_back( {0, 0} ); // initially, both snap_id and val are 0
        }
    }
    
    void set(int index, int val) 
    {
        if (index < 0 || index > length-1) return;
        history[index].push_back( {currSnapId, val} );
    }
    
    int snap() 
    {
        return currSnapId++;
    }
    
    int get(int index, int snap_id) 
    {
        auto& it = history[index]; // vector of pairs of { snap_id, val }

        int left = 0, right = it.size()-1;
        int res = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (it[mid].first <= snap_id) {
                res = it[mid].second;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res;
    }

    private:
    int currSnapId = 0;
    int length;
    vector<vector<pair<int, int>>> history; // idx : { snap_id, val }
};
    
    