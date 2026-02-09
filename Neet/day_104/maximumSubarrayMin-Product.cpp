class Solution 
{
    public:
    int maxSumMinProduct(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        const long long MOD = 1e9 + 7;  

        // build prefix sum
        vector<long long> prefixSum(n+1, 0);
        prefixSum[0] = 0;
        for (int i=1; i<n+1; i++) {
            prefixSum[i] = prefixSum[i-1]+nums[i-1];
        }

        vector<int> prevLess(n, -1);  
        vector<int> nextLess(n, n);   

        stack<int> deck;
        
        // nextLess
        for (int i=0; i<n; i++) {
            while (!deck.empty() && nums[i] < nums[deck.top()]) {  
                int prevIdx = deck.top();
                deck.pop();
                nextLess[prevIdx] = i;  
            }
            deck.push(i);
        }

        deck = stack<int>(); // clear stack

        // prevLess
        for (int i=n-1; i>=0; i--) {
            while (!deck.empty() && nums[i] < nums[deck.top()]) {  
                int prevIdx = deck.top();
                deck.pop();
                prevLess[prevIdx] = i;  
            }
            deck.push(i);
        }

        long long maxProduct = 0;
        for (int i=0; i<n; i++) {
            int left = prevLess[i] + 1;  
            int right = nextLess[i];     
            long long subarraySum = prefixSum[right] - prefixSum[left];  
            maxProduct = max(maxProduct, subarraySum * nums[i]); 
        }

        return maxProduct % MOD;  
    }
};