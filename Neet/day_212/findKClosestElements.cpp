class Solution 
{
    public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        if (arr.size() <= k) return arr;

        // define what's closer
        auto comp = [x](const auto& a, const auto& b) {
            int diffA = abs(a-x);
            int diffB = abs(b-x);
            if (diffA != diffB) {
                return diffA > diffB; // on top
            }
            return a > b; 
        };

        priority_queue<int, vector<int>, decltype(comp)> pq{comp};
        for (int& num : arr) {
            pq.push(num);
        }

        vector<int> res;
        while (!pq.empty() && k > 0) {
            k--;
            res.push_back(pq.top());
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};