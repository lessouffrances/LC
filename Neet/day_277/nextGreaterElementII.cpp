class Solution 
{
    public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        vector<int> res(n, -1);
        stack<int> deck;

        for (int i=0; i<2 * n; i++) {
            while (!deck.empty() && nums[i % n] > nums[deck.top()]) {
                res[deck.top()] = nums[i % n];
                deck.pop();
            }

            deck.push( i % n );
        }
        return res;
    }
};