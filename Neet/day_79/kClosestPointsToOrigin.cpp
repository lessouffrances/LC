class Solution {
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        if (points.empty()) return {};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // { dist, x, y }

        for (auto& pt : points) {
            int x = pt[0];
            int y = pt[1];
            int dist = x * x + y * y;
            pq.push( {dist, x, y} );
        }

        vector<vector<int>> res;
        while (!pq.empty() && k > 0) {
            auto [dist, x, y] = pq.top();
            pq.pop();

            res.push_back( {x, y} );
            k--;
        }
        return res;
    }
};