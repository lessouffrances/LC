class TimeMap 
{
    public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        disk[key].push_back( {timestamp, value} );
    }
    
    string get(string key, int timestamp) 
    {
        if (!disk.count(key)) return "";
        int n = disk[key].size();

        
        // O(logN)
        //        m
        //  [   ....    ]
        //  t1,t2,t3,t4..
        int left = 0, right = n-1;
        string res = "";
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (disk[key][mid].first <= timestamp) {
                res = disk[key][mid].second;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res;
    }

    private:
    // key: { ... {timestamp, value}.... }
    unordered_map<string, vector<pair<int, string>>> disk;
};
   