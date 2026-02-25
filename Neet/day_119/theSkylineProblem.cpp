class Solution 
{
    public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        using Event = pair<int, int>; // x, h
        vector<Event> events;
        _hs.clear();

        // push all buildingEvents into events
        // b: { left, right, height }
        for (auto& b : buildings) {
            events.push_back( {b[0], b[2]} );
            events.push_back( {b[1], -b[2]} );
        }

        // sort events by x
        sort(events.begin(), events.end(), [](const Event& e1, const Event& e2){
            if (e1.first != e2.first) {
                return e1.first < e2.first;
            }
            return e1.second > e2.second;
        });

        vector<vector<int>> res;
        for (auto& e : events) {
            int x = e.first;
            bool isEnter = e.second > 0;
            int h = abs(e.second);

            if (isEnter) {
                if (h > this->maxHeight()) {
                    res.push_back( {x, h} );
                } 
                _hs.insert(h);
            } else {
                _hs.erase(_hs.equal_range(h).first);
                if (h > this->maxHeight()) {
                    res.push_back( {x, this->maxHeight()} );
                }
            }
        }
        return res;
    }
    private:
    int maxHeight() const {
        if (_hs.empty()) return 0;
        return *_hs.rbegin();
    }
    multiset<int> _hs; // multiset is sorted!
};