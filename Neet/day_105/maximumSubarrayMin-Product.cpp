








class Solution 
{
    public:
    int maxSumMinProduct(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        // build prefixSum
        vector<long long> prefixSum(n+1, 0);
        prefixSum[0] = 0;
        for (int i=1; i<n+1; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        // nextLess
        vector<int> nextLess(n, n);
        stack<int> deck;
        for (int i=0; i<n; i++) {
            while (!deck.empty() && nums[i] < nums[deck.top()]) {
                int prevIdx = deck.top();
                deck.pop();
                nextLess[prevIdx] = i;
            }
            deck.push(i);
        }

        deck = stack<int>(); // clear stack

        vector<int> prevLess(n, -1);
        for (int i=n-1; i>=0; i--) {
            while (!deck.empty() && nums[i] < nums[deck.top()]) {
                int prevIdx = deck.top();
                deck.pop();
                prevLess[prevIdx] = i;
            }
            deck.push(i);
        }

        // for each nums[i], find the subarray sum between prevLess and nextLess
        long long maxSumMinProduct = 0;
        for (int i=0; i<n; i++) {
            int left = prevLess[i]+1;
            int right = nextLess[i];
            long long subarraySum = prefixSum[right]-prefixSum[left];
            maxSumMinProduct = max(maxSumMinProduct, (long long)subarraySum * nums[i]);
        }
        return maxSumMinProduct % MOD;
    }
};