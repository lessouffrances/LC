class Solution {
    public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, vector<int>> numToIdxes;
        for (int i = 0; i < n; i++) numToIdxes[nums[i]].push_back(i);
        
        unordered_map<int, vector<long long>> numToIdxPrefixArray;
        for (auto& [num, indexes] : numToIdxes) numToIdxPrefixArray[num] = producePrefixSum(indexes);
        
        vector<long long> res(n, 0);
        for (auto& [num, indexes] : numToIdxes) {
            auto& prefixSumArray = numToIdxPrefixArray[num];
            int m = indexes.size();
            
            for (int j = 0; j < m; j++) {
                long long rightSum = (prefixSumArray[m-1] - prefixSumArray[j]) - (long long)indexes[j] * (m-1-j);
                long long leftSum  = (long long)indexes[j] * j - (j > 0 ? prefixSumArray[j-1] : 0);
                res[indexes[j]] = leftSum + rightSum;
            }
        }
        return res;
    }
        
    private:
    vector<long long> producePrefixSum(vector<int>& arr)
    {
        int n = arr.size();
        vector<long long> res(n, 0);
        res[0] = arr[0];
        for (int i = 1; i < n; i++) res[i] = res[i-1] + arr[i];
        return res;
    }
};