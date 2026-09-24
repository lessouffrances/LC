class SnapshotArray 
{
    public:
    SnapshotArray(int length) 
    {
        // the length tells the index range is
        // [0, length-1]
        this->length = length;
        history.resize(length);
        for (int i=0; i<length; i++) {
            history[i].push_back( {0, 0} );
        }
    }
    
    void set(int index, int val) 
    {
        // invalid queried index
        if (index < 0 || index > length-1) return;
        history[index].push_back( {globalSnapId, val} );
    }
    
    int snap() 
    {
        // every time this method is called, increment
        return globalSnapId++;
    }
    
    // return the val at index when snap_id was taken
    int get(int index, int snap_id) 
    {
        auto& it = history[index];

        int left = 0, right = it.size()-1;
        int res = 0;
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
    int globalSnapId = 0;
    int length;
    vector<vector<pair<int, int>>> history; // idx : {snapId, val}
};
    
    