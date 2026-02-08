









// nums = [2,7,11,15], target = 9
//         i
// seen = {{0,2}}


class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {};
        int n = nums.size();
        unordered_set<int, int> seen; // {num : idx}

        for (int i=0; i<n; i++) {//0
            int diff = target - nums[i];//7
            if (seen.count(diff)) {
                return {i, seen[diff]};
            } 
            seen.insert( {nums[i], i} );
        }
        return {};
    }
};