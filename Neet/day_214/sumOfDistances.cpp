class Solution 
{
    public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, vector<int>> numToIdxes;
        for (int i=0; i<n; i++) numToIdxes[nums[i]].push_back(i);

        unordered_map<int, vector<long long>> numToIdxPrefixArray;
        for (auto& [num, idxes] : numToIdxes) {
            numToIdxPrefixArray[num] = producePrefixArray()
        }

        vector<long long> res(n, 0);
        for (auto& [num, idxes] : numToIdxes) {
            auto& prefixSumArray = numToIdxPrefixArray[num];
            int m = idxes.size();
            
        }




    }

    private:
    vector<long long> producePrefixArray(vector<int>& arr)
    {
        int n = arr.size();
        vector<long long> res(n, 0);
        res[0] = arr[0];
        for (int i=1; i<n; i++) {
            res[i] = res[i-1]+arr[i];
        }
        return res;
    }
};