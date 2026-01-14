class Solution {
    public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        auto comp = [x](const int& a, const int& b) {
            int diffA = abs(a-x);
            int diffB = abs(b-x);
            if (diffA != diffB) {
                return diffA > diffB; // closer on top
            } 
            return a > b; // smaller on top
        };
        priority_queue<int, vector<int>, decltype(comp)> pq{comp};
        for (int num : arr) {
            pq.push(num);
        }

        vector<int> res;
        while (k > 0) {
            int top = pq.top();
            pq.pop();
            res.push_back(top);
            k--;
        }

        sort(res.begin(), res.end());
        return res;
    }
};