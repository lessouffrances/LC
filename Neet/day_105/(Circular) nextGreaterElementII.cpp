










class Solution 
{
    public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        vector<int> nextGreater(n, -1);
        stack<int> deck;
        for (int i=0; i<2*n; i++) {
            int idx = i % n;

            while (!deck.empty() && nums[idx] > nums[deck.top()]) {
                nextGreater[deck.top()] = nums[idx];
                deck.pop();
            }

            if (i < n) {
                deck.push(i);
            }
        }
        return nextGreater;
    }
};