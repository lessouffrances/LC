class TimeMap 
{
    public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        disk[key].push_back( { timestamp, value } );
    }
    
    string get(string key, int timestamp) 
    {
        if (!disk.count(key)) return "";

        auto& info = disk[key];
        int left = 0;
        int right = info.size()-1;

        string res = "";
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (info[mid].first <= timestamp) {
                res = info[mid].second;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res;
    }

    private:
    unordered_map<string, vector<pair<int, string>>> disk;
};
    
    