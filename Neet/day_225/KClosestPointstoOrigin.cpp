class Solution 
{
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        if (points.empty()) return {};

        // { dist, x, y }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, less<tuple<int, int, int>>> pq;
        for (auto& pt : points) {
            int x = pt[0];
            int y = pt[1];
            int dist = x*x + y*y;
            pq.push( {dist, x, y} );
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> res;
        while (!pq.empty()) {
            int x = get<1>(pq.top());
            int y = get<2>(pq.top());
            pq.pop();
            res.push_back( {x, y} );
        }
        return res;
    }
};