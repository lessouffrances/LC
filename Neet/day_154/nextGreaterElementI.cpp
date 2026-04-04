

// nums1 = [4,1,2]

// nums2 = [1,3,4,2]
// deck = [4,2]
// {{1,3}, {3,4}}

class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums2.empty()) return {};
        
        // for nums2
        unordered_map<int, int> nextGreater;
        int n = nums2.size();
        stack<int> deck;
        for (int i=0; i<n; i++) {
            while (!deck.empty() && nums2[i] > deck.top()) {
                auto num = deck.top();
                nextGreater[num] = nums2[i];
                deck.pop();
            }

            deck.push(nums2[i]);
        }

        vector<int> ans;
        for (int num : nums1) {
            if (!nextGreater.count(num)) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(nextGreater[num]);
        }
        return ans;
    }
};