class Solution 
{
    public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        // build nextGreater circularly
        stack<int> deck; // deck has to store indices to avoid duplicate problems
        unordered_map<int, int> nextGreater; // index : num

        for (int i=0; i<2*n; i++) {
            while (!deck.empty() && nums[i % n] > nums[deck.top()]) {
                nextGreater[deck.top()] = nums[i % n];
                deck.pop();
            }
            if (i < n) deck.push(i); 
        }

        vector<int> res;
        for (int i=0; i<n; i++) {
            if (nextGreater.count(i)) {
                res.push_back(nextGreater[i]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};