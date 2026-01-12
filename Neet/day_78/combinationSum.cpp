#include <algorithm>

class Solution {
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<int> startVec;
        int startSum = 0;

        dfs(startVec, startSum, candidates, target, 0);
        return res; 
    }
    
    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currVec, int currSum, vector<int>& options, int target, int start)
    {
        if (currSum == target) {
            res.push_back(currVec);
            return;
        }

        for (int i=start; i<options.size(); i++) {
            currSum += options[i];
            if (currSum > target) return;

            currVec.push_back(options[i]);
            dfs(currVec, currSum, options, target, i);

            // backtrack
            currSum -= options[i];
            currVec.pop_back();
        }

    }
};