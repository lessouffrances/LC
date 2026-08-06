class Solution 
{
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        if (points.empty()) return {};
        int n = points.size();

        // { dist, x, y }
        // maxHeap
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, less<tuple<int, int, int>>> pq;
        for (int i=0; i<n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pq.push( {dist, x, y} );
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            auto& [dist, x, y] = pq.top();
            res.push_back( {x, y} );
            pq.pop();
        }
        return res;
    }
};