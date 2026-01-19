class Solution 
{
    public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) 
    {
        if (nums.empty()) return {};

        int n = nums.size();
        vector<long long> res;

        for (int start=0; start+k<=n; start++) {
            vector<int> subarray;
            for (int i=start; i<start+k; i++) {
                subarray.push_back(nums[i]);
            }

            // build the freq map for this subarray
            unordered_map<int, int> freqMap = buildFreq(subarray);

            // build a pq 
            auto comp = [](const auto& a, const auto& b){
                if (a.second != b.second) {
                    return a.second < b.second; // higher freq on top
                }
                return a.first < b.first; // bigger number on top
            };
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq{comp}; // { num, freq }
            for (auto& [num, count] : freqMap) {
                pq.push( {num, count} );
            }

            long long currRes = 0;
            int count = x;
            while (count > 0 && !pq.empty()) {
                currRes += (long long) pq.top().first * pq.top().second;
                pq.pop();
                count--;
            }

            res.push_back(currRes);
        }
        return res;
            
    }
    private:
    unordered_map<int, int> buildFreq(const vector<int>& nums)
    {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        return freq;
    }
};