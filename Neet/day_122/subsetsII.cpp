// g++ -std=c++14 -o output subsetsII.cpp
// ./output
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
class Solution 
{
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<int> currPath; 
        dfs(0, currPath, 0, nums);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(int currIdx, vector<int>& currPath, int start, vector<int>& options)
    {
        res.push_back(currPath);
        printVec(currPath);

        for (int i=start; i<options.size(); i++) {
            if (i>start && options[i] == options[i-1]) continue; 
            // consider: [1,2,2,3,5]
            // if we do not do this, the dfs will start from 2 again

            currPath.push_back(options[i]);
            dfs(currIdx+1, currPath, i+1, options);
            // increment start by 1, 
            currPath.pop_back();
        }
    }
    void printVec(vector<int>& path)
    {
        printf("[");
        for (int i=0; i<(int)path.size(); i++) {
            if (i > 0) printf(", ");
            printf("%d", path[i]);
        }
        printf("]\n");
    }
};

int main() 
{
    Solution sol;
    vector<int> nums = {1,2,2,3,5};
    sol.subsetsWithDup(nums);
}