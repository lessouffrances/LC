class Solution 
{
    public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        if (arr.size() <= k) return arr;

        auto comp = [x](const auto& a, const auto& b){
            int diffA = abs(a-x);
            int diffB = abs(b-x);
            if (diffA != diffB) {
                return diffA < diffB; // far on top
            }
            return a < b;
        };

        priority_queue<int, vector<int>, decltype(comp)> pq{comp};
        for (int & num : arr) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }   

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};