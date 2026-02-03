class Solution 
{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int i=0; i<n; i++) {
            freq[nums[i]]++;
        }

        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        vector<int> res;
        for (int i=0; i<k; i++) {
            res.push_back(freqVec[i].first);
        }
        return res;
    }
};