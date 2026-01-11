#include <set>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<int> startPerm;
        dfs(startPerm, nums);

        vector<vector<int>> res;
        for (auto& perm : permSet) {
            res.push_back(perm);
        }
        return res;
    }

    private:
    set<vector<int>> permSet;
    void dfs(vector<int>& currPerm, vector<int>& options)
    {
        if (options.empty()) {
            permSet.insert(currPerm);
            return;
        }

        for (int i=0; i<options.size(); i++) {
            int selected = options[i];

            currPerm.push_back(selected);

            // remove the selected from options
            auto it = options.begin() + i;
            options.erase(it);

            // recurse
            dfs(currPerm, options);

            //  backtrack
            options.insert(it, selected);
            currPerm.pop_back();
        }
    }
};

int main() {
    Solution solu = Solution();
    vector<int> test_1 = {1, 2, 3};
    solu.permuteUnique(test_1);
}

