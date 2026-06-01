class Solution {
    public:
        int minArrayLength(vector<int>& nums, int k) {
            if (nums.empty()) return 0;
            int n = nums.size();
            
            // if any 0 exists and k >= 0, entire array collapses to 1
            for (int num : nums) {
                if (num == 0) return 1;
            }
            
            long long product = nums[0];
            int count = 1;
    
            for (int i = 1; i < n; i++) {
                if (product * nums[i] <= k) {
                    product *= nums[i];
                } else {
                    count++;
                    product = nums[i];
                }
            }
            return count;
        }
    };