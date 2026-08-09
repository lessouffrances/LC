class Solution 
{
    public:
    // k is for the window size
    // add all top-x elements in that window
    // [1,1,2,2,3,4,2,3], k = 6, x = 2
    vector<int> findXSum(vector<int>& nums, int k, int x) 
    {
        // maintain sliding window
        int n = nums.size();
        vector<int> res;
        for (int left=0; left+k<=n; left++) {
            vector<int> subarray(nums.begin()+left, nums.begin()+left+k);
            res.push_back(getSumOfTopX(subarray, x));
        }
        return res;
    }

    private:
    int getSumOfTopX(vector<int>& subarray, int x)
    {
        if (subarray.empty()) return 0;
    
        unordered_map<int, int> freq;
        for (int num : subarray) freq[num]++;

        vector<pair<int, int>> distinctArray; // {freq, count}
        for (auto& [num, count] : freq) {
            distinctArray.push_back( {count, num} );
        }

        // sort the distinctArray by freq, higher freq come first
        sort(distinctArray.begin(), distinctArray.end(), [](const auto& a, const auto& b){
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a > b;
        });

        int res = 0;
        for (int i=0; i<min((int)distinctArray.size(), x); i++) {
            res += distinctArray[i].first * distinctArray[i].second;
        }
        return res;
    }
};