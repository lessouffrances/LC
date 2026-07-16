class Solution 
{
    public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
        return dfs(price, special, needs);
    }

    private:
    map<vector<int>, int> memo;

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        // base case: buy everything using the fixed price
        int res = dot(price, needs);

        if (memo.count(needs)) return memo[needs];

        // try each offer to see if the offer can be used at this time
        for (auto& offer : special) {
            vector<int> clone = needs;
            bool valid = true;

            // apply this offer
            for (int j=0; j<needs.size(); j++) {
                clone[j] -= offer[j];
                if (clone[j] < 0) {
                    valid = false;
                    break;
                    // this offer cannot be applied
                }
            }
            if (valid) {
                res = min(res, offer.back() + dfs(price, special, clone));
            }
        }
        return memo[needs] = res;
    }

    // dot product
    int dot(vector<int>& a, vector<int>& b) 
    {
        int sum = 0;
        for (int i=0; i<a.size(); i++) {
            sum += a[i] * b[i];
        }
        return sum;
    }
};