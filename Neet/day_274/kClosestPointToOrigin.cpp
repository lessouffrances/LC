class Solution 
{
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        if (points.empty()) return {};

        // maxHeap
        auto comp = [this](const auto& a, const auto& b){
            return computeDistance(a) < computeDistance(b);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq{comp};

        for (auto& p : points) {
            pq.push(p);
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }

    private:
    int computeDistance(const vector<int>& point)
    {
        return point[0]*point[0] + point[1]*point[1];
    }
};