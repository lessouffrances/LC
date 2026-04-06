

// nums = [1,2,3,4,3]
// doubled = [1,2,3,4,3,1,2,3,4,3]
// deck = [2,3,4,-1,4]
class Solution 
{
    public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        vector<int> doubled = nums;
        doubled.insert(doubled.end(), nums.begin(), nums.end());

        vector<int> ans(n, -1);
        stack<pair<int, int>> deck; // { idx, num }

        for (int i=0; i<2*n; i++) {
            while (!deck.empty() && doubled[i] > deck.top().second) {
                auto [idx, num] = deck.top();
                ans[idx] = doubled[i];
                deck.pop();
            }

            if (i < n) deck.push( {i, doubled[i] });
        }
        return ans;

    }
};