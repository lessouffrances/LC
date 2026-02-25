




class Solution 
{
    public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        if (nums.empty()) return {};
        int n = nums.size();
        int toRemove = n-k; // we can remove at most this many nums

        // stack<int> deck;
        vector<int> deck; // use vectot as a stack
        for (int num : nums) {
            // we want the smaller nums
            while (!deck.empty() && num < deck.back() && toRemove > 0) {
                deck.pop_back();
                toRemove--;
            }
            deck.push_back(num);
        }

        return vector<int>(deck.begin(), deck.begin()+k);
    }
};