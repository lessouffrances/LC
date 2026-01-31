class Solution 
{
    public:
    int subarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        // do not include itself prefix needs n+1
        vector<int>prefixSum(n+1);  
        prefixSum[0] = 0;
        for (int i=1; i<n+1; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        int count = 0;
        for (int i=0; i<n+1; i++) {
            for (int j=i+1; j<n+1; j++) {
                if (prefixSum[j]-prefixSum[i] == k) {
                    count++;
                }
            }
        }
        return count;
    }
};