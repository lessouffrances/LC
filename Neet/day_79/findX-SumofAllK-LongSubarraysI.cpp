class Solution {
    public:
        vector<int> findXSum(vector<int>& nums, int k, int x) {
            int n = nums.size();
            vector<int> res;
    
            for (int start=0; start+k <= n; start++) {
                unordered_map<int, int> freq;
                for (int j=start; j<start+k; j++) {
                    freq[nums[j]]++;
                }

                vector<pair<int, int>> array;
                for (auto& [num, count] : freq) {
                    array.push_back( { num, count } );
                }

                sort(array.begin(), array.end(), [](auto& a, auto& b) {
                    if (a.second != b.second) {
                        return a.second > b.second;
                    } else {
                        return a.first > b.first;
                    }
                });
                int currSum = 0;
                for (int i=0; i<min(x, (int)array.size()); i++) {
                    int num = array[i].first;
                    int count = array[i].second;
                    currSum += num * count;
                }
                res.push_back(currSum);
            }
            return res;
        }
    };
    