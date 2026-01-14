class Solution 
{
    public:
    vector<int> findXSum(vector<int>& nums, int k, int x) 
    {
        int n = nums.size();
        vector<int> res;

        for (int start=0; start+k<=n; start++) {
            unordered_map<int, int> freq;

            // a freq map for the k-subarray
            for (int idx=start; idx<start+k; idx++) {
                freq[nums[idx]]++;
            }

            vector<pair<int, int>> array;
            for (auto& [num, count] : freq) {
                array.push_back( {num, count} );
            }

            sort(array.begin(), array.end(), [](const auto& a, const auto& b) {
                if (a.second != b.second) {
                    return a.second > b.second;
                }
                return a.first > b.first;
            });

            int currSum = 0;

            for (int i=0; i<min((int)array.size(), x); i++) {
                currSum += array[i].first * array[i].second;
            }

            res.push_back(currSum);
        }
        return res;
    }
};