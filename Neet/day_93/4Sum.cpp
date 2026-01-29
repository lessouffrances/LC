class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());
        vector<int> startPath;
        kSum(startPath, 0, 4, target, nums);
        return res;
    }
    
private:
    vector<vector<int>> res;
    
    void kSum(vector<int>& currPath, int start, int k, long long target, vector<int>& options)
    {
        int n = options.size();
        
        // Base case: Two Sum II
        if (k == 2) {
            int l = start, r = options.size() - 1; 
            
            while (l < r) {
                long long sum = (long long)options[l] + options[r];
                
                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    currPath.push_back(options[l]);
                    currPath.push_back(options[r]);
                    res.push_back(currPath);
                    currPath.pop_back();
                    currPath.pop_back();
                    
                    l++;
                    r--;
                    
                    while (l < r && options[l] == options[l - 1]) {
                        l++;
                    }
                    while (l < r && options[r] == options[r + 1]) {
                        r--;
                    }
                }
            }
            return;
        }
        
        // Recursive case: k > 2
        for (int i = start; i < n - k + 1; i++) {
            if (i > start && options[i] == options[i - 1]) continue;
            
            currPath.push_back(options[i]);
            kSum(currPath, i + 1, k - 1, target - options[i], options);
            currPath.pop_back();
        }
    }
};