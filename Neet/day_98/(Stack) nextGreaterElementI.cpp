










// nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]

// nextGreater = {   {1, 3}, {3, 4}  }
// deck = 4, 2



class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty()) return {};

        unordered_map<int, int> nextGreater;
        stack<int> deck;

        for (int num : nums2) {
            while (!deck.empty() && deck.top() < num) {
                nextGreater[deck.top()] = num;
                deck.pop();
            }
            deck.push(num);
        }

        vector<int> res;
        for (int num : nums1) {
            res.push_back( nextGreater.count(num) ? nextGreater[num] : -1);
        }
        return res;
    }
};