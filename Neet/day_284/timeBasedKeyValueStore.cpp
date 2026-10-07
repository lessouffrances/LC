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
        auto& pairs = disk[key];
        int left = 0, right = pairs.size()-1;

        int res = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;

            if (pairs[mid].first <= timestamp) {
                left = mid+1;
                res = mid;
            } else {
                right = mid-1;
            }
        }

        return res == -1 ? "" : pairs[res].second;
    }

    private:
    unordered_map<string, vector<pair<int, string>>> disk;
};
    
    