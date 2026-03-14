class Solution 
{
    public:
    int countSubarrays(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();

        // step 1: find the kIdx in the array
        int kIdx = -1;
        for (int i=0; i<n; i++) {
            if (nums[i] == k) {
                kIdx = i;
                break;
            }
        }

        // A subarray has median k if:
        //   balance == 0  (equal # of elements > k and < k, odd-length subarray)
        //   balance == 1  (one more element > k than < k, even-length subarray)
        //
        // Example: [1, 3, 2], k=2  -> [-1, +1, 0] -> balance=0, median=2
        // Example: [1, 2, 3, 4], k=2 -> [-1, 0, +1, +1] -> balance=1, median=2 

        // Use prefix balance + hashmap to count valid subarrays
        // For a subarray [j+1 ... i] to have balance 0 or 1:
        //   prefixBalance[i] - prefixBalance[j] == 0  =>  prefixBalance[j] == prefixBalance[i]
        //   prefixBalance[i] - prefixBalance[j] == 1  =>  prefixBalance[j] == prefixBalance[i] - 1

        unordered_map<int, int> freq;
        freq[0] = 1;
        int balance = 0;
        int res = 0;

        for (int i=0; i<n; i++) {
            balance += (nums[i] > k) - (nums[i] < k);

            if (i >= kIdx) {
                res += freq[balance] + freq[balance-1];
            } else {
                freq[balance]++;
            }
        }
        return res;
    }
};
