
















class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty()) return {};
        
        // build nextGreater for nums2
        unordered_map<int, int> nextGreaterMap;
        stack<int> deck;

        for (int num : nums2) {
            while (!deck.empty() && num > deck.top()) {
                auto prevNum = deck.top();
                deck.pop();
                nextGreaterMap[prevNum] = num;
            }
            deck.push( num );
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back( nextGreaterMap.count(num) ? nextGreaterMap[num] : -1);
        }

        return ans;
    }
};